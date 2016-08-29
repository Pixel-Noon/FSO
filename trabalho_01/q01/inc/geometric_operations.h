#ifndef GEOMETRIC_OPERATIONS_H
#define GEOMETRIC_OPERATIONS_H

#include "geometric_types.h"

// Return the distance between two points
double side(Point first_point, Point second_point);

// Returns true if the given triangle exists and false otherwise
bool is_triangle(Triangle triangle);

// Return the perimeter of the given triangle
double perimeter(Triangle triangle);

// Return the area of the given triangle
double area(Triangle triangle);

#endif
