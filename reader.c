#include "reader.h"

void* reader_V1(void* data) {
	struct timespec start_time;// Save the clock cycles at the eginning of execution
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	database_v1* db = (database_v1*)data;
	
	lock(&db->reader);// Aquire permission to read readerCount
	
	db->readerCount++;//Indicate one more reader will be reading
	
	if(db->readerCount == 1) {
		lock(&db->resource);//If this is the first reader grab the resource for the readers
	}
	 
	unlock(&db->reader);// Unlock the permission for readerCount
	
	u32 savedIncrementedValue = db->sharedGlobalVariable;// Save the value before sleeping
	
	//Pointlessly wait to immitate computation
	//usleep(100);// Look how hard im working!
	if(db->sharedGlobalVariable != savedIncrementedValue){
		fprintf(stderr, "A writer was allowed to run while a reader was still running\n");
		fprintf(stderr, "Expected value:%d Actual value:%d\n", savedIncrementedValue, db->sharedGlobalVariable);
	}
	
	lock(&db->reader);// Get the permissions for readerCount again
	
	db->readerCount--;// Indicate this reader is finished
	
	if(db->readerCount == 0){
		unlock(&db->resource);// If this was the last reader, release the resource 
	}
	
	unlock(&db->reader);// Unlock the permission for readerCount
	
	struct timespec end_time;	
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	
	u32 total_runtime = timespec_subtract(&end_time, &start_time);// Calculate the total run time in seconds
	u32* toReturn = malloc(sizeof(u32));
	*toReturn = total_runtime;
	
	
	pthread_exit(toReturn);
	
	return NULL;
}

