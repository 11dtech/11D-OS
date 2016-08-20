#include "util.h"

void memory_copy(char *source, char*dest, int nbytes){
	int i;
	for(i=0; i<nbytes; i++){
		*(dest+i) = *(source+1);	//copy memory byte by byte
	}
}

void memory_set(uint8 *dest, uint8 val, uint32 len){
	uint8 *temp = (uint8 *)dest;
	for(;len != 0;len--){
		*temp++ = val;	
	}
}

string int_to_str(int n){
	string str;						//convert int to reversed string
	int i = 0;
	do{
		str[i] = n % 10 + '0';
		i++;
	}while((n /= 10) > 0);
	
	int len = strlength(str);	//reverse string back
	i = 0;
	int j = len -1;
	while(i<(len/2 + len%2)){
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;	
	}
	return str;
}

int str_to_int(string ch){		//convert string to integer
	int n = 0;
	int p = 1;
	int strlen = strlength(ch);
	int i;
	for(i = strlen - 1; i>=0; i--){
		n += ((int)(ch[i] - '0')) * p;
		p *= 10;
	}
	return n;
}

void *malloc(int nbytes){
	char variable[nbytes];
	return &variable;
}


