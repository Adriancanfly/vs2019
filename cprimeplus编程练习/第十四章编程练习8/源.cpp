#include<stdio.h>
#include<string.h>
#define MAXSEAT 12
#define MAXNAME 40
struct flight {
	char num;                       //��λ�ı��
	int state;                                 //��λ��״̬
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
	for (i = 0; i < MAXSEAT; i++)          //Ϊ��λ���,�����Ϊδ��Ԥ��
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
		case 'a':puts("����λ�ĺ���Ϊ");
			for (i = 0; i < MAXSEAT; i++)
			{
				if (seat[i].state == 0)
					printf("%c \n", seat[i].num);
			}break;
		case 'b':puts("����λ��Ϣ\n");
			printf("��λ���    Ԥ������    ��\n");
			for (i = 0; i < MAXSEAT; i++)
			{
				if (seat[i].state == 0)
					printf("%-12c��          ��\n",seat[i].num);
			}break;
		case 'c':printf("��λ���  Ԥ������    ��\n");
			for (i = 0; i < MAXSEAT; i++)
			{
				if (seat[i].state == 0)
					printf("%c        ��       ��\n", seat[i].num);
				else
					printf("%c        %s       %s\n", seat[i].num, seat[i].first, seat[i].last);
			}
			break;
		case 'd':printf("��ѡ��ҪԤ������λ���\n");
			scanf_s("%c", &a,1);
			getchar();
			for (i = 0; i < MAXSEAT; i++)
			{
				if (seat[i].num == a)
				{
					if (seat[i].state == 0)
					{
						printf("��������:");
						s_gets(seat[i].first, MAXNAME);
						printf("��������:");
						s_gets(seat[i].last, MAXNAME);
						printf("Ԥ���ɹ�!\n");
						seat[i].state = 1;
						break;
					}
					else
					{
						printf("%c���ѱ�ԤԼ��\n", seat[i].num);
						break;
					}
				}
			}break;
		case 'e':printf("Ҫȡ���Ǹ�ԤԼ\n");
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
		printf("������a-f֮���ѡ�\n");
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