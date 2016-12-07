#include "spinlock.h"

/**
 * @brief 
 * 		Initializes the lock
 * @param lock
 * 		The lock to initialize
 */
void spinlock_init(spinlock* lock) {
	pthread_mutex_init(&lock->gaurd, NULL);
	lock->locked = 0;
}

/**
 * @brief 
 * 		Locks the provided mutex, exits on failure
 * @param mutex
 * 		The mutex to lock
 */
void lock(spinlock* lock) {
	//first lock the gaurd to avoid race on locked
	pthread_mutex_lock(&lock->gaurd);
	//while the gaurd is locked, wait for it to be unlocked
	while(lock->locked == 1) {
		
		//we need to unlock and lock the gaurd to allow other processes to write to the lock
		pthread_mutex_unlock(&lock->gaurd);
		usleep(0);//sleep so otherprocesses have an easier time accessing the lock
		pthread_mutex_lock(&lock->gaurd);
	}
	//now that the lock is unlocked, lock it, then release the gaurd
	lock->locked = 1;
	pthread_mutex_unlock(&lock->gaurd);
	
}

/**
 * @brief 
 * 		Unlocks the provided mutex, or exits on failure
 * @param mutex
 * 		The mutex to unlock
 */
void unlock(spinlock* lock) {
	pthread_mutex_lock(&lock->gaurd);
	
	lock->locked = 0;
	
	pthread_mutex_unlock(&lock->gaurd);
}