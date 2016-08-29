#include <stdio.h>
#include <string.h>

int main(){
	double number1 = 7.3, number2;
	char s1[100], s2[100];

	double *dPtr;

	dPtr = &number1;
	
	printf("%lf\n", *dPtr);

	dPtr = &number2;

	printf("%lf\n", *dPtr);

	printf("%p\n", &number1);

	printf("%p\n", dPtr);

	scanf("%s", s1);

	strcpy(s2, s1);

	printf("%d\n", strcmp(s1, s2));

	printf("%s\n", strcat(s1,s2));

	printf("%zd\n", strlen(s1));
}
