#include "writers.h"

void writer_V1(database_v1* data){
	
	if(lock(&data->resource) != 0){
		//Some error trying to get the lock, exiting
		pthread_exit(1);
	}
	
	//Pointlessly wait to immitate computation
	sleep(1);
	
	unlock(&data->resource);
}

void writer_V2(database_v1* data){
	
}

void writer_V3(database_v1* data){
	
}