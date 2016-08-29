#ifndef INPUT_FUNCTIONS_H
#define INPUT_FUNCTIONS_H

#include "geometric_types.h"

// Start application
void start();

// Print menu. Returns true while active otherwise false
bool menu();

// Ask input for a new triangle then show its perimeter and area, if it's a valid triangle otherwise print error message
void new_triangle();

// Error message shown in case of invalid triangle
void triangle_error();

// Exit application
void stop();

#endif
