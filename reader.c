#include "reader.h"

void reader_V1(database_v1* db) {
	pthread_mutex_lock(&db->reader);
	
	db->readers++;
	
	if(db->reader == 1) {
		pthread_mutex_lock
	}
}