#include "database.h"

volatile u8 readyToStart = 0;

FILE* outputStream = NULL;

void initDB1(database_v1* db) {
	//initialize the mutexes
	spinlock_init(&db->reader);
	spinlock_init(&db->resource);
	//set the reader count to 0
	db->readerCount = 0;
	db->sharedGlobalVariable = 0;
}

void initDB2(database_v2* db) {
	//initialize the mutexes
	spinlock_init(&db->resource);
	spinlock_init(&db->readtry);
	spinlock_init(&db->rentry);
	spinlock_init(&db->writer);
	spinlock_init(&db->reader);
	//set the counts to 0
	db->readerCount = 0;
	db->writerCount = 0;
	
	db->sharedGlobalVariable = 0;
}

void initDB3(database_v3* db){
	//initialize the mutexes
	spinlock_init(&db->resource);
	spinlock_init(&db->readwrite);
	//set the counts to 0
	db->readerCount = 0;
	db->writerCount = 0;
	
	db->sharedGlobalVariable = 0;
}