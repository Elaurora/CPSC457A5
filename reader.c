#include "reader.h"

void reader_V1(void* arg) {
	database_v1* db = (database_v1*)arg;
	
	lock(&db->reader);

	db->readerCount++;
	
	if(db->readerCount == 1) {
		lock(&db->resource);
	}
}