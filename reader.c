#include "reader.h"

void* reader_V1(void* data) {
	database_v1* db = (database_v1*)data;
	
	lock(&db->reader);// Aquire permission to read readerCount
	
	db->readerCount++;//Indicate one more reader will be reading
	
	if(db->readerCount == 1) {
		lock(&db->resource);//If this is the first reader grab the resource for the readers
	}
	 
	unlock(&db->reader);// Unlock the permission for readerCount
	
	//Pointlessly wait to immitate computation
	sleep(1);// Look how hard im working!
	
	lock(&db->reader);// Get the permissions for readerCount again
	
	db->readerCount--;// Indicate this reader is finished
	
	if(db->readerCount == 0){
		unlock(&db->resource);// If this was the last reader, release the resource 
	}
	
	unlock(&db->reader);// Unlock the permission for readerCount
	
	return NULL;// return nothing, this function accomplished nothing.
}