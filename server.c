#include "server.h"


void runTest1() {
	 database_v1 db1;
	 initDB1(&db1);
	 
	 pthread_t readers[500];
	 pthread_t writers[100];
	 
	 for(u32 readerCount = 5; readerCount <= 500; readerCount += 5) {
		 
#if VERBOSE
		printf("Starting readerCount == %d\n", readerCount);
#endif
		 double sumTurnaroundReader = 0.0;
		 
		 u32 index = 0;
		 
		 while(index < readerCount || index < 100) {
			if(index < readerCount) {
				 pthread_create(&(readers[index]), NULL, reader_V1, (void*)&db1);
			}
			 
			if(index < 100) {
				`pthread_create(&(writers[index]), NULL, writer_V1, (void*)&db1);
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
			//printf("%u\n", nanoSeconds);
			sumTurnaroundReader += nanoSeconds;

			free(status);
		 }
		 
		 for(u32 i = 0; i < 100; i++) {
			 pthread_join(writers[i], NULL);
		 }
		 
#if VERBOSE
		 printf("Average turn around for %d readers, 100 writers is: %lf\n", readerCount, sumTurnaroundReader / readerCount);
#else
		printf("%lf\n", sumTurnaroundReader / readerCount);
#endif	


	}

}