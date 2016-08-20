#ifndef UTIL_H
#define UTIL_H
#include "types.h"
#include "string.h"

void memory_copy(char *source, char *dest, int nbytes);	//copy memory

void memory_set(uint8 *dest, uint8 val, uint32 len);	//set val to memory address

string int_to_str(int n);	//convert integer to string

int str_to_int(string ch);

void *malloc(int nbytes);

#endif
