#include<stdio.h>

void p1(void);
void p2(void);
void p3(void);
int main(void)
{
	int b;
	void (*a[3])(void);
	a[0] = p1;
	a[1] = p2;
	a[2] = p3;
	printf("0-----p1\n");
	printf("1-----p2\n");
	printf("2-----p3\n");
	scanf_s("%d", &b);
	a[b]();

	return 0;
}
void p1(void)
{
	printf("p1函数激活成功!");
}
void p2(void)
{
	printf("p2函数激活成功！");
}
void p3(void)
{
	printf("p3函数激活成功！");
}