#ifndef SPINLOCK_H
#define SPINLOCK_H

#include "types.h"


typedef struct spinlock {
	pthread_mutex_t gaurd;
	u8 locked;
} spinlock;

/**
 * @brief 
 * 		Initializes the lock
 * @param lock
 * 		The lock to initialize
 */
void spinlock_init(spinlock* lock);

/**
 * @brief 
 * 		Locks the provided mutex, exits on failure
 * @param mutex
 * 		The mutex to lock
 */
void lock(spinlock* lock);

/**
 * @brief 
 * 		Unlocks the provided mutex, or exits on failure
 * @param mutex
 * 		The mutex to unlock
 */
void unlock(spinlock* lock);

#endif