#ifndef DATABASE_H
#define DATABASE_H

#include "types.h"
#include "spinlock.h"

extern volatile u8 readyToStart;
extern FILE* outputStream;

/**
 * The shared resouces between all processes for version 1 function threads
 */
typedef struct database_v1 {
	/*
	 * The mutex on the shared resource
	 */
	spinlock resource;
	
	/**
	 * The mutex shared by readers
	 */
	spinlock reader;
	
	/*
	 * How many readers are currently in the critical section
	 */
	u32 readerCount;
	
	/**
	 * A test shared variable between all the processes
	 */
	u32 sharedGlobalVariable;
} database_v1;

/**
 * @brief 
 * 		Initializes a db_v1 struct by initializing its mutexes and setting its reader count to 0
 * @param db
 * 		The database struct to initialize
 */
void initDB1(database_v1* db);

/**
 * The shared resouces between all processes for version 2 function threads
 */
typedef struct database_v2 {
	/*
	 * The mutex on the shared resource
	 */
	spinlock resource;
	
	/*
	 * This mutex allows writers to bully readers away from accessing the shared resource
	 */
	spinlock readtry;
	
	/*
	 * needed to ensure that the program favors writers
	 */
	spinlock rentry;
	
	/**
	 * The mutex for the writerCount variable
	 */
	spinlock writer;
	
	/**
	 * The mutex for the readerCount variable
	 */
	spinlock reader;
	
	/**
	 * The number of writer threads currently executing
	*/
	u32 writerCount;
	
	/**
	 * The number of reader threads currently executing
	*/
	u32 readerCount;
	
	/**
	 * A test shared variable between all the processes
	 */
	u32 sharedGlobalVariable;
} database_v2;

/**
 * @brief 
 * 		Initializes a db_v2 struct by initializing its mutexes and setting its reader and writer counts to 0
 * @param db
 * 		The database struct to initialize
 */
void initDB2(database_v2* db);

/**
 * The shared resouces between all processes for version 3 function threads
 */
typedef struct database_v3 {
	/*
	 * The mutex on the shared resource
	 */
	spinlock resource;
	
	/**
	 * The mutex for the writerCount and readerCount variables
	 */
	spinlock readwrite;
	
	/**
	 * The number of writer threads currently executing
	*/
	u32 writerCount;
	
	/**
	 * The number of reader threads currently executing
	*/
	u32 readerCount;
	
	/**
	 * A test shared variable between all the processes
	 */
	u32 sharedGlobalVariable;
} database_v3;

/**
 * @brief 
 * 		Initializes a db_v3 struct by initializing its mutexes and setting its reader and writer counts to 0
 * @param db
 * 		The database struct to initialize
 */
void initDB3(database_v3* db);

#endif