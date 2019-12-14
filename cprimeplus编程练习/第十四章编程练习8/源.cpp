#include<stdio.h>
#include<string.h>
#define MAXSEAT 12
#define MAXNAME 40
struct flight {
	char num;                       //座位的编号
	int state;                                 //座位的状态
	char first[MAXNAME];
	char last[MAXNAME];
};
char get_t(void);
char* s_gets(char* st, int n);
void menu(void);

int main(void)
{
	struct flight seat[MAXSEAT];
	int i;
	char c, a='\0';
	for (i = 0; i < MAXSEAT; i++)          //为座位编号,并标记为未被预定
	{
		seat[i].num = ('A' + i);
		seat[i].state = 0;
	}

	menu();
	c = get_t();
	while (c != 'f')
	{
		switch (c)
		{
		case 'a':puts("空座位的号码为");
			for (i = 0; i < MAXSEAT; i++)
			{
				if (seat[i].state == 0)
					printf("%c \n", seat[i].num);
			}break;
		case 'b':puts("空座位信息\n");
			printf("座位编号    预定人姓    名\n");
			for (i = 0; i < MAXSEAT; i++)
			{
				if (seat[i].state == 0)
					printf("%-12c无          无\n",seat[i].num);
			}break;
		case 'c':printf("座位编号  预定人姓    名\n");
			for (i = 0; i < MAXSEAT; i++)
			{
				if (seat[i].state == 0)
					printf("%c        无       无\n", seat[i].num);
				else
					printf("%c        %s       %s\n", seat[i].num, seat[i].first, seat[i].last);
			}
			break;
		case 'd':printf("请选择要预定的座位编号\n");
			scanf_s("%c", &a,1);
			getchar();
			for (i = 0; i < MAXSEAT; i++)
			{
				if (seat[i].num == a)
				{
					if (seat[i].state == 0)
					{
						printf("请输入姓:");
						s_gets(seat[i].first, MAXNAME);
						printf("请输入名:");
						s_gets(seat[i].last, MAXNAME);
						printf("预定成功!\n");
						seat[i].state = 1;
						break;
					}
					else
					{
						printf("%c座已被预约！\n", seat[i].num);
						break;
					}
				}
			}break;
		case 'e':printf("要取消那个预约\n");
			scanf_s("%c", &a,1);
			getchar();
			for (i = 0; i < MAXSEAT; i++)
			{
				if (seat[i].num == a)
				{
					seat[i].state = 0;
					break;
				}
			}break;
		}
		menu();
		c = get_t();
	}
	
	return 0;
}
char get_t()
{
	char c='0';
	scanf_s("%c", &c,1);
	while (c < 'a' || c>'f')
	{
		printf("请输入a-f之间的选项！\n");
		scanf_s("%c", &c,1);
	}
	while (getchar() != '\n')
		continue;

	return c;
}
void menu()
{
	printf("To choose a function enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphaberical list of seats\n");
	printf("d) Assign a customer to s3at assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n");
}
char* s_gets(char* st, int n)
{
	char* find;
	char* ret_val;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}