#include "writers.h"

void writer_V1(database_v1* data){
	
	if(pthread_mutex_lock(data->resource) != 0){
		
	}
	
	//Pointlessly wait to immitate computation
	
	pthread_mutex_unlock(data->resouece);
}

void writer_V2(database_v1* data){
	
}

void writer_V3(database_v1* data){
	
}