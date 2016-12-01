
#include "server.h"

int main(int argc, char **argv)
{
	/*
	 * 
	 * Test driver for V1
	 */
#if VERBOSE
	printf("starting case 1\n");
#endif
	 runTest1();
	 runTest2();
	 runTest3();

	return 0;
}
