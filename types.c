#include "types.h"

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
