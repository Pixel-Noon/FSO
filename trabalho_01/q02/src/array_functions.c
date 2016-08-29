#include "array_functions.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int* create_array(int size){
	int* array = (int*) malloc(size * sizeof(int));
	
	memset(array, 0, size);

	return array;
}

void add(char const elem[], int *array, int i){
	int number = 0;

	sscanf(elem, "%d", &number);

	array[i] = number;
}

void sort(int *array, int size){
	qsort(array, size, sizeof(array[0]), compare);
}

int compare(const void *a, const void *b){
	int int_a = * ((int*) a);
	int int_b = * ((int*) b);

	if(int_a == int_b) 
		return 0;
	else if(int_a < int_b)
		return -1;
	else
		return 1;
}

void destroy_array(int* array){
	free(array);
}
