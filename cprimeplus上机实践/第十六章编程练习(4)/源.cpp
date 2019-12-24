#include<stdio.h>
#include<stdlib.h>
#define NUM 20
#define TIMES 7

void rand_s(int*, int, int);

int main(void)
{
	int a[NUM];
	
	for (int i = 0; i < NUM; i++)
		a[i] = i + 1;
	rand_s(a, NUM, TIMES);

	return 0;
}

void rand_s(int* t, int n, int m)
{
	int i = 0;
	int s;
	while (i++ < m)
	{
		s = rand() % 20;
		while (t[s] == 0)
			s = rand() % 20;
		printf("num: (%2d)   %2d %2d\n",i, s, t[s]);
		t[s] = 0;
	}
}