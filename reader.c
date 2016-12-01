#include "reader.h"

void reader_V1(database_v1* db) {
	lock(&db->reader);
	
	db->readerCount++;
	
	if(db->readerCount == 1) {
		lock(&db->resource);
	}
}