#ifndef DATABASE_H
#define DATABASE_H

#include "types.h"

/*
 * The shared resouces between all processes
 */
typedef struct database_v1 {
	/*
	 * The mutex on the shared resource
	 */
	pthread_mutex_t resource;
	
	/**
	 * The mutex shared by readers
	 */
	pthread_mutex_t reader;
	
	/*
	 * How many readers are currently in the critical section
	 */
	u32 readerCount;
	
	/**
	 * A test shared variable between all the processes
	 */
	u32 shaderedGlobalVariable;
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