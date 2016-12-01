#include "database.h"

void initDB1(database_v1* db) {
	//initialize the mutexes
	pthread_mutex_init(&db->reader, NULL);
	pthread_mutex_init(&db->resource, NULL);
	//set the reader count to 0
	db->readerCount = 0;
	db->shaderedGlobalVariable = 0;
}
