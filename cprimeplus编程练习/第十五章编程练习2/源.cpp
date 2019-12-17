#include<stdio.h>
#include<stdlib.h>
int get_t(char* a);
void put_t(int);
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("²ÎÊý²»¹»£¡");
		exit(EXIT_FAILURE);
	}
	char* a = argv[1];
	char* b = argv[2];
	int c, d, e;
	c = get_t(a);
	d = get_t(b);
	printf("%d %d\n", c, d);
	e = ~c;
	printf("%d\n", e);
	put_t(e);
	e = ~d;
	put_t(e);
	e = c & d;
	put_t(e);
	e = c | d;
	put_t(e);
	e = c ^ d;
	put_t(e);

	return 0;
}
int get_t(char* s)
{
	int i = 0;
	int n = 0;
	while (s[i] != '\0')
	{
		n <<= 1;
		n |= s[i] - '0';
		i++;
	}
	return n;
}
void put_t(int n)
{
	int i = 32;
	int mask = 1;
	char in[33];
	while(i-->0)
	{
		in[i] = (mask & n) + '0';
		n >>= 1;
	}
	in[32] = '\0';
	puts(in);
}