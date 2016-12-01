#include "types.h

void lock(pthread_mutex_t* mutex) {
	u32 returnVal = pthread_mutex_lock(mutex);
	
	if(returnVal) {
		printf("Mutex Lock Failed\n");
		pthread_exit(1);
	}
}

void unlock(pthread_mutex_t* mutex) {
	u32 returnVal = pthread_mutex_unlock(mutex);
	
	if(returnVal) {
		printf("Mutex Unlock Failed\n");
		pthread_exit(1);
	}
}
