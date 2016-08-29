#include "geometric_types.h"

#include <stdio.h>
#include <math.h>


double side(Point first_point, Point second_point){
	double euclidean_distance = pow(first_point.x - second_point.x, 2) +
								pow(first_point.y - second_point.y, 2);

	euclidean_distance = sqrt(euclidean_distance);

	return euclidean_distance;
}

bool is_triangle(Triangle triangle){
	bool _flag = true;
	
	double distance[3] = {0,0,0};
	
	double biggest = 0;
	int biggest_index = 0;

	int i;
	for(i=0; i<3; i++){
		distance[i] = side(triangle.points[i], triangle.points[(i+1)%3]);
		if(biggest < distance[i]){
			biggest = distance[i];
			biggest_index = i;
		}
	}

	int first_index = (biggest_index+1)%3;
	int second_index = (biggest_index+2)%3;

	if(distance[first_index] + distance[second_index] > distance[biggest_index])
		_flag = true;
	else
		_flag = false;

	return _flag;
}

double perimeter(Triangle triangle){
	double result = 0;

	int i;
	for(i=0; i<3; i++){
		result += side(triangle.points[i], triangle.points[(i+1)%3]);
	}

	return result;
}

double area(Triangle triangle){
   double result = 0;

   double _perimeter = perimeter(triangle);
   _perimeter /= 2;
   result = _perimeter;
   for(int i=0; i<3; i++){
	   result *= (_perimeter - side(triangle.points[i], triangle.points[(i+1)%3]));
   }

   result = sqrt(result);

   return result;
}
