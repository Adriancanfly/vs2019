//11.4 arrchar
#include<stdio.h>
#define SLEN 40
#define LIM 5
int main(void)
{
	const char* mytalents[LIM] = {
		"Adding number swiftly",
		"Multiplying accurately","Stashing data",
		"Following in structions to the letter",
		"Understanding the C language"
	};                                                   //mytalents�洢5��ָ�룬�ַ�������ֵΪ��ַ���ַ�������ĸ�ĵ�ַ��
	char yourtalents[LIM][SLEN] = {
		"Walking in a straight line",
		"Sleeping","Watching telebision",
		"Mailing letters","Reading email"
	};                                                  //��ά����
	int i;

	puts("Let's compare talents.");
	printf("%-36s %-25s\n", "My Talents", "Your Talents");
	for (i = 0; i < LIM; i++)
		printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);  //mytalents��yourtalents�����ƣ������ǲ��ܶ�yourtalents��������
	printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n", sizeof(mytalents), sizeof(yourtalents));

	return 0;
}