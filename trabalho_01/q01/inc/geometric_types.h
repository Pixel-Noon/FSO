#ifndef GEOMETRIC_TYPES_H
#define GEOMETRIC_TYPES_H

#define NO_TRIANGLE -1

enum bool {
    false = 0,
    true
};

typedef int bool;

typedef struct struct_point{
    double x;
    double y;
} Point;

typedef struct struct_triangle{
    Point points[3];
} Triangle;

#endif
