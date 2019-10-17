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
	};                                                   //mytalents存储5个指针，字符字面量值为地址（字符串首字母的地址）
	char yourtalents[LIM][SLEN] = {
		"Walking in a straight line",
		"Sleeping","Watching telebision",
		"Mailing letters","Reading email"
	};                                                  //二维数组
	int i;

	puts("Let's compare talents.");
	printf("%-36s %-25s\n", "My Talents", "Your Talents");
	for (i = 0; i < LIM; i++)
		printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);  //mytalents和yourtalents很相似！！但是不能对yourtalents递增！！
	printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n", sizeof(mytalents), sizeof(yourtalents));

	return 0;
}