#include<stdio.h>
int tran_t(char* st);

int main(void)
{
	char a[] = "01001001";
	int b;
	b = tran_t(a);
	printf("%d  ..", b);

	return 0;
}

int tran_t(char* st)
{
	int i = 0;
	int n = 0;
	while (st[i] != '\0')
	{
		n <<= 1;
		n |= st[i] - '0';
		i++;
	}
	return n;
}