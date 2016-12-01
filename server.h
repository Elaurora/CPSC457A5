#ifndef SERVER_H
#define SERVER_H

#include "database.h"
#include "reader.h"
#include "writers.h"


/**
 * @brief 
 * 		runs a test on V1 of the reader/writer algorithm
 */
void runTest1();

/**
 * @brief 
 * 		runs a test on V2 of the reader/writer algorithm
 */
void runTest2();

/**
 * @brief 
 * 		runs a test on V3 of the reader/writer algorithm
 */
void runTest3();

/**
 * @brief 
 * 		Runs a single reader test case and returns the average wait time for the readers to run
 * @param db
 * 		The shared database for all the threads
 * @param readers
 * 		An array of reader threads
 * @param readerCount
 * 		How many reader threads to initialize
 * @param writers
 * 		An array of writer threads
 * @param writerCount
 * 		How many writer thread to initialize
 * @return 
 * 		The average runtime for the reader threads
 */
double readerTestCase(void *(*readerTask) (void *), void *(*writerTask) (void *), void* db, pthread_t* readers, u32 readerCount, pthread_t* writers, u32 writerCount);

/**
 * @brief 
 * 		Runs a single reader test case and returns the average wait time for the readers to run
 * @param db
 * 		The shared database for all the threads
 * @param readers
 * 		An array of reader threads
 * @param readerCount
 * 		How many reader threads to initialize
 * @param writers
 * 		An array of writer threads
 * @param writerCount
 * 		How many writer thread to initialize
 * @return 
 * 		The average runtime for the writer threads
 */
double writerTestCase(void *(*readerTask) (void *), void *(*writerTask) (void *), void* db, pthread_t* readers, u32 readerCount, pthread_t* writers, u32 writerCount);

#endif