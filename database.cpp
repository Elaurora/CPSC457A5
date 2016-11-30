#include "database.h"

void initDB1(database_v1* db) {
	pthread_mutex_init(&db->reader, NULL);
	pthread_mutex_init(&db->resource, NULL);
	db->readers = 0;
}
