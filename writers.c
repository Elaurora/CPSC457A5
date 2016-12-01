#include "writers.h"

void* writer_V1(void* data){
	clock_t start_time = clock();// Save the clock cycles at the eginning of execution
	
	database_v1* db = (database_v1*)data;
	
	lock(&db->resource);// Aquire the permission to pretend to write
	
	u32 savedIncrementedValue = ++(db->sharedGlobalVariable);// Save the value before sleeping
	
	
	//Pointlessly wait to immitate computation
	sleep(1);// WORK SO HARD
	
	if(db->sharedGlobalVariable != savedIncrementedValue){
		fprintf(stderr, "More than one writer was allowed into the critical section at once\n");
		fprintf(stderr, "Expected value:%d Actual value:%d\n", savedIncrementedValue, db->sharedGlobalVariable);
	}
	
	unlock(&db->resource);// unlock the permission to write or read
	
	u32 total_runtime = clock() - start_time;// Calculate the total run time in seconds
	
	return (void*)total_runtime;
}

void* writer_V2(void* data){
	clock_t start_time = clock();// Save the clock cycles at the eginning of execution
	
	database_v1* db = (database_v1*)data;
	
	lock(&db->resource);// Aquire the permission to pretend to write
	
	u32 savedIncrementedValue = ++(db->sharedGlobalVariable);// Save the value before sleeping
	
	
	//Pointlessly wait to immitate computation
	sleep(1);// WORK SO HARD
	
	if(db->sharedGlobalVariable != savedIncrementedValue){
		fprintf(stderr, "More than one writer was allowed into the critical section at once\n");
		fprintf(stderr, "Expected value:%d Actual value:%d\n", savedIncrementedValue, db->sharedGlobalVariable);
	}
	
	unlock(&db->resource);// unlock the permission to write or read
	
	u32 total_runtime = clock() - start_time;// Calculate the total run time in seconds
	
	return (void*)total_runtime;
}

void* writer_V3(void* data){
	return NULL;
}