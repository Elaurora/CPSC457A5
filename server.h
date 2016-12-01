#ifndef SERVER_H
#define SERVER_H

#include "database.h"
#include "reader.h"
#include "writers.h"


/**
 * @brief 
 * 		runs a test on V1 of the reader/writer algorithm
 */
void runTest1() {
	 database_v1 db1;
	 initDB1(&db1);
	 
	 pthread_t reader[500];
	 pthread_t writers[100];
	 
	 for(u32 readerCount = 5; readerCount <= 500; readerCount += 5) {
		 
		 double sumTurnaroundReader = 0.0;
		 
		 for(u32 i = 0; i < readerCount; i++) {
			 pthread_create(&(reader[i]), NULL, reader_V1, (void*)&db1);
		 }
		 
		 for(u32 i = 0; i < 100; i++) {
			 pthread_create(&(writer[i]), NULL, writer_V1, (void*)&db1);
		 }
		 
		 //all the threads are running atm
		 
		 for(u32 i = 0; i < readerCount; i++) {
			 void* status;
			 
			 pthread_join(&(reader[i], status);
			 
			 u32 clockCycles = (u32)status;
			 
			 sumTurnaroundReader += (double)(clockCycles / CLOCKS_PER_CYCLE);
		 }
		 
		 for(u32 i = 0; i < 100; i++) {
			 pthread_join(&(writer[i]), NULL);
		 }
		 
#if VERBOSE
		 printf("Average turn around for %d readers, 500 writers is: %lf\n", readerCount, sumTurnaroundReader / readerCount);
#else
		printf("%lf\n", sumTurnaroundReader / readerCount);
#endif	

	}

}


#endif