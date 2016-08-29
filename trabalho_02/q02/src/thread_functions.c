#include "thread_functions.h"
#include <pthread.h>
#include <stdio.h>

void* set_one(void* arguments){
	Args *args = arguments; 

	args->w[args->index] = 1;

	pthread_exit(&args->index);
}

void* check_bigger(void* arguments){
	Args *args = arguments;

	int firstNum = args->firstNum;
	int secondNum = args->secondNum;

	printf("Checking values %d %d.\n", firstNum, secondNum);

	if (firstNum > secondNum){
		printf("%d is bigger than %d.\n", firstNum, secondNum);
		pthread_exit(&args->secondIndex);
	}
	else{
		printf("%d is bigger than %d.\n", secondNum, firstNum);
		pthread_exit(&args->firstIndex);
	}
}

void* check_max(void* arguments){
	Args *args = arguments;

	if(args->w[args->index])
		printf("Max value in array = %d\n", args->x[args->index]);
	else
		pthread_exit(NULL);

	// Just to remove warning from compile
	return NULL;
}