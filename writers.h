#ifndef WRITERS_H
#define WRITERS_H

#include "database.h"

/**
 * @brief First version of the writer function thread. Simply waits until the resource is available which
 * will occur when all readers are finished reading
 * 
 */
void* writer_V1(void* data);

/**
 * @brief 
 */
void* writer_V2(void* data);

/**
 * @brief 
 */
void* writer_V3(void* data);

#endif