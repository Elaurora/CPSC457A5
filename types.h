#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define VERBOSE 0
#define TO_CONSOLE 0
#define SLEEP_IN_CS 1000

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

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