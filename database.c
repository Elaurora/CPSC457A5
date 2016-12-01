#include "database.h"

volatile u8 readyToStart = 0;

FILE* outputStream = NULL;

void initDB1(database_v1* db) {
	//initialize the mutexes
	pthread_mutex_init(&db->reader, NULL);
	pthread_mutex_init(&db->resource, NULL);
	//set the reader count to 0
	db->readerCount = 0;
	db->sharedGlobalVariable = 0;
}

void initDB2(database_v2* db) {
	//initialize the mutexes
	pthread_mutex_init(&db->resource, NULL);
	pthread_mutex_init(&db->readtry, NULL);
	pthread_mutex_init(&db->rentry, NULL);
	pthread_mutex_init(&db->writer, NULL);
	pthread_mutex_init(&db->reader, NULL);
	//set the counts to 0
	db->readerCount = 0;
	db->writerCount = 0;
	
	db->sharedGlobalVariable = 0;
}

void initDB3(database_v3* db){
	//initialize the mutexes
	pthread_mutex_init(&db->resource, NULL);
	pthread_mutex_init(&db->readwrite, NULL);
	//set the counts to 0
	db->readerCount = 0;
	db->writerCount = 0;
	
	db->sharedGlobalVariable = 0;
}