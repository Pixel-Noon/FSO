#include "array_functions.h"
#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, int size){
	for(int i=0; i<size; i++){
		printf("%d ", array[i]);
	}
	printf("\n\n");
}

int *set_array(char *argv[], int size){
	int *x;

	x = malloc(sizeof(int)*size);
	for(int i=2; i<size+2; i++){
		int num;
		sscanf(argv[i], "%d", &num);

		x[i-2] = num;
	}

	printf("Size of array = %d\n", size);
	printf("Array = ");
	print_array(x, size);

	return x;
}