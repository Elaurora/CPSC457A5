#ifndef READER_H
#define READER_H

#include "database.h"

/**
 * @brief 
 * 		The reader function for v1 of the solution. Claims the resource mutex as long as there is at
 * least on reader. Releases resource when there are no remaining readers.
 */
void* reader_V1(void* data);

void* reader_V2(void* data);

void* reader_V3(void* data);


#endif