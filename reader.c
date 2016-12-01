#include "reader.h"

void* reader_V1(void* data) {
	database_v1* db = (database_v1*)data;
	
	lock(&db->reader);
	
	db->readerCount++;
	
	if(db->readerCount == 1) {
		lock(&db->resource);
	}
	 
	unlock(&db->reader);
	
	//Pointlessly wait to immitate computation
	sleep(1);
	
	lock(&db->reader);
	
	db->readerCount--;
	
	if(db->readerCount == 0){
		unlock(&db->resource);
	}
	
	unlock(&db->reader);
	
	return NULL;
}