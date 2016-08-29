#ifndef THREAD_FUNCTIONS_H
#define	THREAD_FUCNTIONS_H

typedef struct struct_args{
	int index;
	int *w;
	int *x;
	int firstIndex;
	int firstNum;
	int secondIndex;
	int secondNum;
} Args;

void *set_one(void*);

void *check_bigger(void*);

void *check_max(void*);

#endif