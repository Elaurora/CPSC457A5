#include "server.h"

int main(int argc, char **argv)
{
#if VERBOSE
	printf("starting case 1\n");
#endif

	 //runTest1();
	 
#if VERBOSE
	printf("starting case 2\n");
#endif
	printf("\n");
	//runTest2();
	 
#if VERBOSE
	printf("starting case 3\n");
#endif
	printf("\n");
	runTest3();

	return 0;
}
