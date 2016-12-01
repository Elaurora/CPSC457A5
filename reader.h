#ifndef READER_H
#define READER_H

#include "database.h"

/**
 * @brief First version of the reader thread. Claims the resource mutex as long as there is at
 * least on reader. Releases resource when there are no remaining readers.
 * @param data - A pointer to the database structure containg the semaphores/mutexes and other variables.
 */
void* reader_V1(void* data);

/**
 * @brief Second version of the reader thread. Attempts to read the value only if there are no currently 
 * running writers. If there are, all readers will wait until all writers have run to completion.
 * @param data - A pointer to the database structure containg the semaphores/mutexes and other variables.
 */
void* reader_V2(void* data);

/**
 * @brief Third version of the reader thread. Attempts to read the value only if there are no writers attempting to write. Otherwise it
 * will wait until the writers that were waiting when it came in to finish, then it will aquire the lock and read.
 * @param data - A pointer to the database structure containg the semaphores/mutexes and other variables.
 */
void* reader_V3(void* data);


#endif