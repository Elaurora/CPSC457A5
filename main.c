#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	/*
	 * 
	 * Test driver for V1
	 */
	 
	 database_v1 db1;
	 initDB1(&db1);
	 
	 pthread reader;
	 pthread_create(&reader, NULL, reader_V1, (void*)&db1);
	 
	 reader_V1(&db1);
	 writer_V1(&db1);
	 
	return 0;
}
