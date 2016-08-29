#include "input_functions.h"
#include "geometric_operations.h"

#include <stdio.h>
#include <stdlib.h>

void start(){
	system("clear");

	bool active = true;

	while(active){
		active = menu();
	}
}

bool menu(){
	bool active = true;

	printf("1 - Create new triangle.\n");
	printf("2 - Exit.\n");

	int option = 0;
	while(scanf("%d", &option) != 1){
		printf("Not a valid option. Choose again.\n");
		
		printf("1 - Create new triangle.\n");
		printf("2 - Exit.\n");

		getchar();
	}

	switch(option){
		case 1: new_triangle();
				active = true;
				break;
		case 2: stop();
				active = false;
				break;
		default: printf("Not a valid option. Choose again.\n");
	}

	return active;
}

void new_triangle(){
	Triangle triangle;

	int i;
	for(i=0; i<3; i++){
		printf("Insert coordinates for the point %d(x, y)\n", i+1);
		if(scanf("%lf %lf", &triangle.points[i].x, &triangle.points[i].y) != 2){
			printf("Invalid coordinates. Try again.\n");
			getchar();
			return;
		}
		
		getchar();
	}

	bool _flag = is_triangle(triangle);
	if(_flag){
		printf("Perimeter: %.4lf\n", perimeter(triangle));
		printf("Area: %.4lf\n", area(triangle));
	}
	else{
		printf("It is a invalid triangle\n");
	}
}

void stop(){
	printf("Closing...");
}
