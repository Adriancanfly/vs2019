#include<stdio.h>
int bits(int);
int main(void)
{
	int i = 15;
	int a;

	a = bits(i);
	printf("%d打开了%d个位!", i, a);

	return 0;
}

int bits(int n)
{
	int i = 8 * sizeof(int);
	int m, b = 0;
	int mask = 1;

	for (m = 0; m < i; m++,n>>=1)
	{
		if (mask & n)
			b++;
	}
	return b;
}