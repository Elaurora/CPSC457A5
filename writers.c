#include "writers.h"

void* writer_V1(void* data){
	database_v1* db = (database_v1*)data;
	
	lock(&db->resource);
	
	//Pointlessly wait to immitate computation
	sleep(1);
	
	unlock(&db->resource);
	
	return NULL;
}

void* writer_V2(void* data){
	return NULL;
}

void* writer_V3(void* data){
	return NULL;
}