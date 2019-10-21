#include<stdio.h>
int main(void)
{
	const char* mesg = "Don't be a fool!";
	const char* copy;

	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);//mesg为一个指针，mesg的地址为&mesg,下同
	printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);

	return 0;

}
//因为一个字符字面量为一个地址且程序整个作用域都存在