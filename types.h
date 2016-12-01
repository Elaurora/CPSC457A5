#ifndef TYPES_H
#define TYPES_H

#define VERBOSE 0

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

/**
 * @brief 
 * 		Locks the provided mutex, exits on failure
 * @param mutex
 * 		The mutex to lock
 */
void lock(pthread_mutex_t* mutex);

/**
 * @brief 
 * 		Unlocks the provided mutex, or exits on failure
 * @param mutex
 * 		The mutex to unlock
 */
void unlock(pthread_mutex_t* mutex);

/**
 * @brief 
 * 		Subtracts 2 timespecs, assumes the difference is less than 4 seconds,
 * 		and left > right
 * @param left
 * 		The lHS
 * @param right
 * 		The RHS
 * @return 
 * 		The number of nanoseconds between left and right
 */
u32 timespec_subtract(struct timespec* left, struct timespec* right);

#endif