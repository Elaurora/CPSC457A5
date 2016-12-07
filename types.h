#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

//if 1, lots of details about the trails is printed to the output stream, if 0 minimal data is printed
#define VERBOSE 1
//if 1, output is streamed to stdout, if 0 the output of the program is printed to cpsc457_log.txt
#define TO_CONSOLE 1
//how long each thread should spend sleeping in its critical section, in microseconds
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