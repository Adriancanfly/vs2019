#include<stdio.h>
int rotate_1(unsigned int, int);
void put_t(int);
int main(void)
{
	int i = 7;
	unsigned int n;
	n = rotate_1(i, 2);
	put_t(n);
}
int rotate_1(unsigned int n,int m)
{
	int i;
	unsigned int j = 0;
	int mask = 1;
	for (i = 0; i < m; i++)
	{
		j |= (n & mask)<<31;
		n >>= 1;
		if (i + 1 < m)
		{
			j >>= 1;
		}
	}
	n |= j;

	return n;
}
void put_t(int n)
{
	char a[33];
	int i = 33 - 1;
	while (i-- > 0)
	{
		a[i] = (n & 1) + '0';
		n >>= 1;
	}
	a[32] = '\0';
	puts(a);

}