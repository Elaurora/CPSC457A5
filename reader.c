#include "reader.h"


void* reader_V1(void* data) {
	database_v1* db = (database_v1*)data;
	
	while(!readyToStart) {
		usleep(1);
	}

	struct timespec start_time;// Save the clock cycles at the eginning of execution
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	
	
	
	lock(&db->reader);// Aquire permission to read readerCount
	
	db->readerCount++;//Indicate one more reader will be reading
	
	if(db->readerCount == 1) {
		lock(&db->resource);//If this is the first reader grab the resource for the readers
	}
	 
	unlock(&db->reader);// Unlock the permission for readerCount
	
	//beginning of critical section
	
	u32 savedIncrementedValue = db->sharedGlobalVariable;// Save the value before sleeping
	usleep(1000); //1ms sleep
	//Pointlessly wait to immitate computation
	//usleep(100);// Look how hard im working!
	if(db->sharedGlobalVariable != savedIncrementedValue){
		fprintf(stderr, "A writer was allowed to run while a reader was still running\n");
		fprintf(stderr, "Expected value:%d Actual value:%d\n", savedIncrementedValue, db->sharedGlobalVariable);
	}
	//printf("%d\n", db->readerCount);
	// end of critical section
	
	lock(&db->reader);// Get the permissions for readerCount again
	
	db->readerCount--;// Indicate this reader is finished
	
	if(db->readerCount == 0){
		unlock(&db->resource);// If this was the last reader, release the resource 
	}
	
	unlock(&db->reader);// Unlock the permission for readerCount
	
	struct timespec end_time;	
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	
	u32 total_runtime = timespec_subtract(&end_time, &start_time);// Calculate the total run time in seconds
	u32* toReturn = (u32*)malloc(sizeof(u32));
	*toReturn = total_runtime;
	
	
	pthread_exit(toReturn);
	
	return NULL;
}

void* reader_V2(void* data){
	database_v2* db = (database_v2*)data;
	
	while(!readyToStart) {
		usleep(1);
	}
	
	struct timespec start_time;// Save the clock cycles at the eginning of execution
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	
	
	
	lock(&db->rentry);// Aquire permission to attempt to aquire pemission to read
	lock(&db->readtry);// Aquire permission to read
	lock(&db->reader); // Aquire permission to readerCount variable
	
	db->readerCount++;
	if(db->readerCount == 1){
		lock(&db->resource); // If this is the first reader, aquire the permission to the resource so no writers interfere
	}
	
	unlock(&db->reader); // Unlock permission to readerCount variable
	unlock(&db->readtry); // Unlock permission to read
	unlock(&db->rentry); // Unlock permission to attempt to read
	
	//beginning of critical section
	
	u32 savedIncrementedValue = db->sharedGlobalVariable;// Save the value before sleeping
	
	usleep(1000); //1ms sleep
	
	if(db->sharedGlobalVariable != savedIncrementedValue){
		fprintf(stderr, "A writer was allowed to run while a reader was still running\n");
		fprintf(stderr, "Expected value:%d Actual value:%d\n", savedIncrementedValue, db->sharedGlobalVariable);
	}
	
	// end of critical section
	
	lock(&db->reader); // Aquire permission to readerCount variable
	
	db->readerCount--;
	if(db->readerCount == 0){
		unlock(&db->resource); // if this was the last reader, release the lock on the resource
	}
	
	unlock(&db->reader); // Unlock permission to the readerCount variable
	
	struct timespec end_time;	
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	
	u32 total_runtime = timespec_subtract(&end_time, &start_time);// Calculate the total run time in seconds
	u32* toReturn = (u32*)malloc(sizeof(u32));
	*toReturn = total_runtime;
	
	
	pthread_exit(toReturn);
	
	return NULL;
}

void* reader_V3(void* data){
	database_v3* db = (database_v3*)data;
	
	while(!readyToStart) {
		usleep(1);
	}
	
	struct timespec start_time;// Save the clock cycles at the eginning of execution
	clock_gettime(CLOCK_MONOTONIC, &start_time);
	
	lock(&db->readwrite);// Get permissions to the count variables
	if(db->writerCount > 0 || db->readerCount == 0){
		//If this is the first reader entering, OR there is at least one writer in the game
		unlock(&db->readwrite);// Unlock permissions to the count variables
		lock(&db->resource); // Aquire permission to access the resource.
		lock(&db->readwrite); // re-aquire the permissions on the count variables
	}
	
	db->readerCount++;// Increment the reader counter
	unlock(&db->readwrite);// Unlock permissions to the count variables
	
	//beginning of critical section
	
	u32 savedIncrementedValue = db->sharedGlobalVariable;// Save the value before sleeping
	
	usleep(1000); //1ms sleep
	if(db->sharedGlobalVariable != savedIncrementedValue){
		fprintf(stderr, "A writer was allowed to run while a reader was still running\n");
		fprintf(stderr, "Expected value:%d Actual value:%d\n", savedIncrementedValue, db->sharedGlobalVariable);
	}
	
	// end of critical section
	
	lock(&db->readwrite); // Aquire permission to the count variables
	db->readerCount--; // Decrement the reader count
	if(db->readerCount == 0){
		unlock(&db->resource);//If this was the last running reader release the resource.
	}
	unlock(&db->readwrite);// Unlock the permission to the count variables
	
	struct timespec end_time;	
	clock_gettime(CLOCK_MONOTONIC, &end_time);
	
	u32 total_runtime = timespec_subtract(&end_time, &start_time);// Calculate the total run time in seconds
	u32* toReturn = (u32*)malloc(sizeof(u32));
	*toReturn = total_runtime;
	
	
	pthread_exit(toReturn);
	
	return NULL;
}