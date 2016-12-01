#include "server.h"


void runTest1() {
	 database_v1 db1;
	 initDB1(&db1);
	 
	 pthread_t readers[500];
	 pthread_t writers[100];
	 
	 //do all the reader tests
	 for(u32 readerCount = 5; readerCount <= 500; readerCount += 5) {
		 readerTestCase(reader_V1, writer_V1, &db1, readers, readerCount, writers, 100);
	 }
	 printf("\n");
	 for(u32 writerCount = 5; writerCount <= 100; writerCount += 5) {
		 writerTestCase(reader_V1, writer_V1, &db1, readers, 500, writers, writerCount);
	 }

}


void runTest2() {
	//init the db
	 database_v2 db2;
	 initDB2(&db2);
	 
	 //init the readers writers
	 pthread_t readers[500];
	 pthread_t writers[100];
	 
	 //do all the reader tests
	 for(u32 readerCount = 5; readerCount <= 500; readerCount += 5) {
		 readerTestCase(reader_V2, writer_V2, &db2, readers, readerCount, writers, 100);
	 }
	 printf("\n");
	 //do all the writer tests
	 for(u32 writerCount = 5; writerCount <= 100; writerCount += 5) {
		 writerTestCase(reader_V2, writer_V2, &db2, readers, 500, writers, writerCount);
	 }

}


void runTest3() {
	//init the db
	 database_v3 db3;
	 initDB3(&db3);
	 //init the readers writers
	 pthread_t readers[500];
	 pthread_t writers[100];
	 
	 //do all the reader tests
	 for(u32 readerCount = 5; readerCount <= 500; readerCount += 5) {
		 readerTestCase(reader_V3, writer_V3, &db3, readers, readerCount, writers, 100);
	 }
	 printf("\n");
	 for(u32 writerCount = 5; writerCount <= 100; writerCount += 5) {
		 writerTestCase(reader_V3, writer_V3, &db3, readers, 500, writers, writerCount);
	 }

}

double readerTestCase(void *(*readerTask) (void *), void *(*writerTask) (void *), void* db1, pthread_t* readers, u32 readerCount, pthread_t* writers, u32 writerCount) {

	
#if VERBOSE
		printf("Starting readerCount == %d\n", readerCount);
#endif
		 double sumTurnaroundReader = 0.0;
		 
		 u32 index = 0;
		 
		 while(index < readerCount || index < writerCount) {
			if(index < readerCount) {
				 pthread_create(&(readers[index]), NULL, readerTask, db1);
			}
			 
			if(index < writerCount) {
				pthread_create(&(writers[index]), NULL, writerTask, db1);
			}
			
			index++;
		 }
		 
	
#if VERBOSE
		printf("Threads launched, joining...\n");
#endif	 
		 //all the threads are running atm
		 
		 for(u32 i = 0; i < readerCount; i++) {
			 void* status = NULL;
			 
			 pthread_join(readers[i], &status);
			
			u32 nanoSeconds = *(u32*)status;
			sumTurnaroundReader += nanoSeconds;
			free(status);
			
		 }
		
		 for(u32 i = 0; i < writerCount; i++) {
			 pthread_join(writers[i], NULL);
		 }
		 
#if VERBOSE
		 printf("Average turn around for %d readers, %d writers is: %lf\n", readerCount, writerCount, sumTurnaroundReader / readerCount);
#else
		printf("%d\t%d\t%lf\n", readerCount, writerCount, sumTurnaroundReader / readerCount);
#endif	

	return sumTurnaroundReader / readerCount;
}

double writerTestCase(void *(*readerTask) (void *), void *(*writerTask) (void *), void* db1, pthread_t* readers, u32 readerCount, pthread_t* writers, u32 writerCount) {
	
	
#if VERBOSE
		printf("Starting writerCount == %d\n", writerCount);
#endif
		 double sumTurnaroundWriter = 0.0;
		 
		 u32 index = 0;
		 
		 while(index < readerCount || index < writerCount) {
			if(index < readerCount) {
				 pthread_create(&(readers[index]), NULL, readerTask, db1);
			}
			 
			if(index < writerCount) {
				pthread_create(&(writers[index]), NULL, writerTask, db1);
			}
			
			index++;
		 }
		 
	
#if VERBOSE
		printf("Threads launched, joining...\n");
#endif	 
		 //all the threads are running atm
		 
		 for(u32 i = 0; i < writerCount; i++) {
			 void* status = NULL;
			 
			 pthread_join(writers[i], &status);
			
			u32 nanoSeconds = *(u32*)status;
			sumTurnaroundWriter += nanoSeconds;
			free(status);
			
		 }
		
		 for(u32 i = 0; i < readerCount; i++) {
			 pthread_join(readers[i], NULL);
		 }
		 
#if VERBOSE
		 printf("Average turn around for %d readers, %d writers is: %lf\n", readerCount, writerCount, sumTurnaroundWriter / readerCount);
#else
		printf("%d\t%d\t%lf\n", readerCount, writerCount sumTurnaroundWriter / readerCount);
#endif	

	return sumTurnaroundWriter / readerCount;
}