#ifndef WRITERS_H
#define WRITERS_H

#include "database.h"

/**
 * @brief First version of the writer function thread. Simply waits until the resource is available which
 * will occur when all readers are finished reading
 * @param data - A pointer to the database structure containg the semaphores/mutexes and other variables.
 */
void* writer_V1(void* data);

/**
 * @brief Second version of the writer function thread. When a writer begins, it waits for any currently 
 * running readers to finish execution and prevents any more from beginning execution. It then prevents
 * any more readers from beginning until all writers are finished
 * @param data - A pointer to the database structure containg the semaphores/mutexes and other variables.
 */
void* writer_V2(void* data);

/**
 * @brief Third version of the writer function thread. When a writer enters, it simply indicates that there is a new
 * writer entering the game, then waits until it can grab the resource lock.
 * @param data - A pointer to the database structure containg the semaphores/mutexes and other variables.
 */
void* writer_V3(void* data);

#endif