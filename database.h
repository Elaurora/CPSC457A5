#ifndef DATABASE_H
#define DATABASE_H

#include <pthread.h>
#include "types.h"

typedef struct database_v1 {
	pthread_mutex_t resource;
	pthread_mutex_t reader;
	u32 readers;
} database_v1;

/**
 * @brief 
 * 		Initializes a db_v1 struct by initializing its mutexes and settings its reader count to 0
 * @param db
 * 		The database struct to initialize
 */
void initDB1(database_v1* db);


typedef struct database_v2 {
	
} database_v2;

typedef struct database_v3 {
	
} database_v3;

#endif