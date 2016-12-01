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
