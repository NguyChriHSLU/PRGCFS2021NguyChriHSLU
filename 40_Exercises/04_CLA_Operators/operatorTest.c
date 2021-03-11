#include <stdio.h>


int main(int argc, char *argv[] )
{
	
	unsigned short largeShort = 32760;
	printf("after init: %d\n", largeShort);
	
	largeShort = largeShort + 12345;
	printf("after adding: %d\n", largeShort);
	
	int numerator = 19, denominator = 5;
	float result;
	result = (float)numerator / denominator;
	
	printf("%d divided by %d = %0.2f\n", numerator, denominator, result);
	
	
	float e = 2.718281828f;
	printf("after init: %f\n", e);
	e++;
	printf("after increment: %f\n", e);
	e--;
	printf("before increment: %f\n", e);
	
	
	double dblNumber = 12.8;
	printf("after init: %f\n", dblNumber);
	dbleNumber = dbleNumber % 3;
	
	
	return 0;
}
