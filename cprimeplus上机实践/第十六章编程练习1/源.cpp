#include<stdio.h>
#define HARMONIC_AVERAGE(X,Y) (1/((1/(X)+1/(Y))/2))

int main(void)
{
	double a, b, c;

	scanf_s("%lf %lf", &a, &b);
	c = HARMONIC_AVERAGE(a, b);
	printf("%lf", c);

	return 0;
}