#include "array_functions.h"
#include "steps.h"
#include "thread_functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	system("clear");

	int size;

	sscanf(argv[1], "%d", &size);

	if(size == 0){
		printf("Numero de inteiros inválido.\n");
		return 0;
	}
	// First step. For some reason i can't modularize this block of code.
	pthread_t *threads = (pthread_t*) malloc(size * sizeof(pthread_t));
	int *w = (int*) malloc(size * sizeof(int));
	int *x = set_array(argv, size);

	Args *args = (Args*) malloc(size * sizeof(Args));

	for(long i=0; i<size; i++){
		args[i].w = w;
		args[i].index = i;
		pthread_create(&threads[i], NULL, set_one, (void*)&args[i]);
	}
	for(int i=0; i<size; i++){
		pthread_join(threads[i], NULL);
	}

	printf("Array w before second step = ");
	print_array(w, size);

	// Second step
	second_step(threads, w, x, size);

	// Third Step
	third_step(threads, w, x, size);

	free(w);
	free(x);
	free(threads);

	pthread_exit(NULL);
}