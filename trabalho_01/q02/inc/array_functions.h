#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

void add(char const elem[], int *array, int i);

int* create_array(int size);

void sort(int* array, int size);

int compare(const void *a, const void *b);

void destroy_array(int* array);

#endif
