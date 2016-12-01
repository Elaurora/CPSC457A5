#include "database.h"
#include "reader.h"
#include "writers.h"


int main(int argc, char **argv)
{
	/*
	 * 
	 * Test driver for V1
	 */
	 
	 database_v1 db1;
	 initDB1(&db1);
	 
	 pthread_t reader;
	 pthread_create(&reader, NULL, reader_V1, (void*)&db1);
	 
	 pthread_t writer;
	 pthread_create(&writer, NULL, writer_V1, (void*)&db1);

	 
	return 0;
}
