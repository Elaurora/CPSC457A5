#include "server.h"

int main(int argc, char **argv)
{
#if TO_CONSOLE
	outputStream = stdout;
#else
	outputStream = fopen("cpsc457A5_Log.txt", "w");
#endif
	
	
#if VERBOSE
	fprintf(outputStream, "starting case 1\n");
#endif

	 runTest1();
	 
#if VERBOSE
	fprintf(outputStream, "starting case 2\n");
#endif
	fprintf(outputStream, "\n");
	runTest2();
	 
#if VERBOSE
	fprintf(outputStream, "starting case 3\n");
#endif
	fprintf(outputStream, "\n");
	runTest3();

#if TO_CONSOLE

#else
	fclose(outputStream);
#endif

	return 0;
}
