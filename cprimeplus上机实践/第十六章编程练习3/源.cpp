#include<stdio.h>
#include<time.h>

void test(double);
int main(void)
{
	double time;
	printf("enter running time: ");
	scanf_s("%lf", &time);
	test(time);

	return 0;
}

void test(double t)
{
	long i = 0;
	double a = (double)clock();
	double b;
	do
	{
		i++;
		b = (double)clock();
	} while (((b - a) / CLOCKS_PER_SEC) < t);
	printf("it runs %lf times", ((b - a) / CLOCKS_PER_SEC));
}