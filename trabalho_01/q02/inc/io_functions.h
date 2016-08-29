#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS_H

typedef enum {
	crescent, decrescent
} Order;

void start(int argc, char const *argv[]);

void print_crescent(int* array, int size);

void print_decrescent(int* array, int size);

#endif
