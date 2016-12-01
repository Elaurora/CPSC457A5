#include "writers.h"

void* writer_V1(void* data){
	database_v1* db = (database_v1*)data;
	
	lock(&db->resource);// Aquire the permission to pretend to write
	
	//Pointlessly wait to immitate computation
	sleep(1);// WORK SO HARD
	
	unlock(&db->resource);// unlock the permission to write or read
	
	return NULL;
}

void* writer_V2(void* data){
	return NULL;
}

void* writer_V3(void* data){
	return NULL;
}