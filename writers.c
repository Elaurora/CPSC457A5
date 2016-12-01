#include "writers.h"

void* writer_V1(void* data){
	struct timespec start_time;// Save the clock cycles at the eginning of execution
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	
	database_v1* db = (database_v1*)data;
	
	lock(&db->resource);// Aquire the permission to pretend to write
	
	// Beginning of critical section
	
	u32 savedIncrementedValue = ++(db->sharedGlobalVariable);// Save the value before sleeping
	
	
	//Pointlessly wait to immitate computation
	// WORK SO HARDs
	
	if(db->sharedGlobalVariable != savedIncrementedValue){
		fprintf(stderr, "More than one writer was allowed into the critical section at once\n");
		fprintf(stderr, "Expected value:%d Actual value:%d\n", savedIncrementedValue, db->sharedGlobalVariable);
	}
	
	// end of critical section
	
	unlock(&db->resource);// unlock the permission to write or read
	
	struct timespec end_time;	
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	
	u32 total_runtime = timespec_subtract(&end_time, &start_time);// Calculate the total run time in seconds
	
	u32* toReturn = (u32*)malloc(sizeof(u32));
	*toReturn = total_runtime;
	
	pthread_exit(toReturn);
	
	return NULL;
}

void* writer_V2(void* data){
	struct timespec start_time;// Save the clock cycles at the eginning of execution
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	
	database_v2* db = (database_v2*)data;
	
	lock(&db->writer);// aquire lock for the writerCount variable
	db->writerCount++;// increment the writerCount variable
	if(db->writerCount == 1){
		lock(&db->readtry);// If this is the first writer, aquire the lock to prevent readers from entering
	}
	unlock(&db->writer);// Unlock the writerCount mutex
	lock(&db->resource);// Get permission to write the variable
	
	// Beginning of critical section
	u32 savedIncrementedValue = ++(db->sharedGlobalVariable);// Save the value before sleeping
	
	
	if(db->sharedGlobalVariable != savedIncrementedValue){
		fprintf(stderr, "More than one writer was allowed into the critical section at once\n");
		fprintf(stderr, "Expected value:%d Actual value:%d\n", savedIncrementedValue, db->sharedGlobalVariable);
	}
	
	//end of critical section
	
	unlock(&db->resource);// Unlock the permissions to write to the shared variable
	lock(&db->writer);// aquire lock for the writerCount variable
	db->writerCount--;// decrement the writerCount variable
	if(db->writerCount == 0){
		unlock(&db->readtry);// If this was the final writer thread unlock the mutex to allow readers to readers in
	}
	unlock(&db->writer);// Unlock the writerCount mutex
	
	struct timespec end_time;	
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	
	u32 total_runtime = timespec_subtract(&end_time, &start_time);// Calculate the total run time in seconds
	
	u32* toReturn = (u32*)malloc(sizeof(u32));
	*toReturn = total_runtime;
	
	pthread_exit(toReturn);
	
	return NULL;
}

void* writer_V3(void* data){
	struct timespec start_time;// Save the clock cycles at the eginning of execution
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	
	database_v3* db = (database_v3*)data;
	
	lock(&db->readwrite);// Aquire permission to the count variables
	db->writerCount++;// increment the number of writers
	unlock(&db->readwrite);// Unlock permision to the count variables
	
	lock(&db->resource);// get permission to enter the critical section
	
	// Beginning of critical section
	u32 savedIncrementedValue = ++(db->sharedGlobalVariable);// Save the value before sleeping
	
	
	if(db->sharedGlobalVariable != savedIncrementedValue){
		fprintf(stderr, "More than one writer was allowed into the critical section at once\n");
		fprintf(stderr, "Expected value:%d Actual value:%d\n", savedIncrementedValue, db->sharedGlobalVariable);
	}
	
	//end of critical section
	
	lock(&db->readwrite);// Get permission to the count variables
	db->writerCount--; // decrement the number of writers
	unlock(&db->readwrite); // unlock permission to the count variables
	
	unlock(&db->resource);// unlock permission to the resource
	
	struct timespec end_time;	
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	
	u32 total_runtime = timespec_subtract(&end_time, &start_time);// Calculate the total run time in seconds
	
	u32* toReturn = (u32*)malloc(sizeof(u32));
	*toReturn = total_runtime;
	
	pthread_exit(toReturn);
	
	return NULL;
}