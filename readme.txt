------------------------------------------------------
				CPSC 457 - Assignment 5
				Patrick Settle - 10158828
				Joshua Walters - 10154369
------------------------------------------------------
Compilation Notes:
We developed on cygwin with gcc

!!Also!!

There are 3 important settings in types.h

//if 1, lots of details about the trails is printed to the output stream, 
//if 0, minimal data is printed
#define VERBOSE 1
//if 1, output is streamed to stdout, 
//if 0, the output of the program is printed to cpsc457_log.txt
#define TO_CONSOLE 1
//how long each thread should spend sleeping in its critical section, in microseconds
#define SLEEP_IN_CS 1000

-------------------------------------------------------
Please also note that all printed times are in nanoseconds
				