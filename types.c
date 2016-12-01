#include "types.h"

void lock(pthread_mutex_t* mutex) {
	u32 returnVal = pthread_mutex_lock(mutex);
	
	if(returnVal) {
		fprintf(stderr, "Mutex Lock Failed\n");
		pthread_exit((void*)&returnVal);
	}
}

void unlock(pthread_mutex_t* mutex) {
	u32 returnVal = pthread_mutex_unlock(mutex);
	
	if(returnVal) {
		fprintf(stderr, "Mutex Unlock Failed\n");
		pthread_exit((void*)&returnVal);
	}
}

#define nSperS 1000000000

u32 timespec_subtract(struct timespec* left, struct timespec* right) {
	if(left->tv_nsec < right->tv_nsec) {
		//if left nsec is less than right usec, 
		//get the difference
		u32 diffN = (nSperS - right->tv_nsec - left->tv_nsec);
		u32 diffS = left->tv_sec + 1 - right->tv_sec;
		
		return diffS * nSperS + diffN;
	} else {
		u32 diffN = left->tv_nsec - right->tv_nsec;
		u32 diffS = left->tv_sec - right->tv_sec;
		
		return diffS * nSperS + diffN;
	}
}
