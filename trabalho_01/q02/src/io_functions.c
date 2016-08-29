#include "io_functions.h"
#include "array_functions.h"

#include <string.h>
#include <stdio.h>

void start(int argc, char const *argv[]){
	Order order = crescent;

	int size = 0;
	for(int i=1; i<argc; i++){
		if(strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "-d") == 0){
			order = argv[i][1] == 'd' ? crescent : decrescent;
		} else {
			size++;
		}
	}

	int *array = create_array(size);

	for(int i=1; i<argc; i++){
		if(strcmp(argv[i], "-r") != 0 && strcmp(argv[i], "-d") != 0){
			add(argv[i], array, size);
		}
	}

	sort(array, size);

	if(order == crescent)
		print_crescent(array, size);
	else
		print_decrescent(array, size);

	destroy_array(array);
}

void print_crescent(int* array, int size){
	for(int i=0; i<size; i++)
		printf("%d ", array[i]);
}

void print_decrescent(int* array, int size){
	for(int i=size-1; i>=0; i--)
		printf("%d ", array[i]);
}
