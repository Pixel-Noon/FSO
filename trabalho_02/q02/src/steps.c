#include "steps.h"
#include "thread_functions.h"
#include "array_functions.h"

#include <stdio.h>
#include <stdlib.h>

// For some reason this isn't working.
void first_step(pthread_t *threads, int *w, int size){
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

	free(args);
}

void second_step(pthread_t *threads, int *w, int *x, int size){
	int newSize = (size*size-1)/2;

	Args *args = (Args*) malloc(newSize * sizeof(Args));
	threads = (pthread_t*) malloc(newSize * sizeof(pthread_t));

	for(int i=0, k=0; i<size; i++){
		for(int j=i+1; j<size; j++, k++){
			args[k].firstNum = x[i];
			args[k].firstIndex = i;
			args[k].secondNum = x[j];
			args[k].secondIndex = j;

			pthread_create(&threads[k], NULL, check_bigger, (void*)&args[k]);
		}
	};

	for(int i=0; i<newSize; i++){
		void *status;
		pthread_join(threads[i], &status);

		int number = *((int *)status);

		w[number] = 0;
	}

	printf("Array w after second step = ");
	print_array(w, size);

	free(args);
}

void third_step(pthread_t *threads, int *w, int *x, int size){
	Args *args = (Args*) malloc(size * sizeof(Args));
	for(long i=0; i<size; i++){
		args[i].index = i;
		args[i].x = x;
		args[i].w = w;
		pthread_create(&threads[i], NULL, check_max, (void*)&args[i]);
	}
	for(int i=0; i<size; i++){
		pthread_join(threads[i], NULL);
	}

	free(args);
}