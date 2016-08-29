#ifndef STEPS_H
#define STEPS_H

#include <pthread.h>

void first_step(pthread_t*, int*, int);

void second_step(pthread_t*, int*, int*, int);

void third_step(pthread_t*, int*, int*, int);

#endif