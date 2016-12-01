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

void runTest2();

void runTest3();

/**
 * @brief 
 * 		Runs a single reader test case and returns the average wait time for the readers
 * @param db1
 * @param readers
 * @param readerCount
 * @param writers
 * @param writerCount
 * @return 
 */
double readerTestCase(void *(*readerTask) (void *), void *(*writerTask) (void *), database_v1* db1, pthread_t* readers, u32 readerCount, pthread_t* writers, u32 writerCount);

double writerTestCase(void *(*readerTask) (void *), void *(*writerTask) (void *), database_v1* db1, pthread_t* readers, u32 readerCount, pthread_t* writers, u32 writerCount);

#endif