#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
char* s_gets(char* st, int n);
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int judge;           //�ж��Ƿ�ɾ��
};

int main(void)
{
	FILE* fp;
	struct book library[MAXBKS];
	errno_t err;
	int count = 0, c, size, i, k, h;
	size = sizeof(struct book);
	
	if ((err = fopen_s(&fp, "aa.txt", "a+b")) != 0)
	{
		fprintf(stderr, "�ļ���ʧ��!");
		exit(EXIT_FAILURE);
	}

	rewind(fp);

	while (count < MAXBKS && fread(&library[count], size, 1, fp))
		count++;
	fclose(fp);
	if (count == 0)
	{
		printf("û���κ��飬�������!(˫��������ӣ�\n");
		printf("�������:");
		while (s_gets(library[count].title, MAXTITL) != NULL && count < MAXBKS && library[count].title[0] != '\0')
		{
			printf("��������:");
			s_gets(library[count].author, MAXTITL);
			printf("����۸�:");
			scanf_s("%f", &library[count++].value);
			while (getchar() != '\n')
				continue;
			if (count == MAXBKS)
				printf("�ļ�������\n");
			else
				printf("���������˫��������ӣ�:");
		}
	}
	for (i = 0; i < count; i++)
	{
		library[i].judge = 0;                //������������Ϊδɾ��
	}
	printf("1> �鿴���            2> ��������\n");
	printf("3> ɾ������            4> ��������\n");
	printf("5> �˳�������\n");
	scanf_s("%d", &c);
	while (c != 5 && c >= 1 && c <= 5)
	{
		while (getchar() != '\n')
			continue;
		switch (c)
		{
		case 1:
			for (i = 0,h=0; i < count; i++)
			{
				if (library[i].judge == 0)
					printf("%s by %s ,value: %.2f\n", library[i].title, library[i].author, library[i].value);
				else
				{
					printf("��ɾ��\n");
					h++;
				}
			}
			printf("����%d����\n", count-h);
			break;
		case 2: printf("Ҫ�޸��Ǳ���?\n");
			for (i = 0; i < count; i++)
			{
				if (library[i].judge == 0)
					printf("%d) %s by %s ,value: %f\n", i + 1, library[i].title, library[i].author, library[i].value);
				else
					printf("��ɾ��\n");
			}
			printf("�������:");
			scanf_s("%d", &i);
			while (getchar() != '\n')
				continue;
			printf("��������:");
			s_gets(library[i - 1].title, MAXTITL);
			printf("��������:");
			s_gets(library[i - 1].author, MAXAUTL);
			printf("����۸�:");
			scanf_s("%f", &library[i - 1].value);
			while (getchar() != '\n')
				continue;
			library[i - 1].judge = 0;                        //���޸��˱�ɾ�������ݣ�������Ϊδɾ����
			break;
		case 3: printf("Ҫɾ���Ǹ�����?\n");
			for (i = 0; i < count; i++)
			{
				if (library[i].judge == 0)
					printf("%d) %s by %s,value: %f\n", i + 1, library[i].title, library[i].author, library[i].value);
				else
					printf("��ɾ��\n");
			}
			printf("�������:");
			scanf_s("%d", &i);
			while (getchar() != '\n')
				continue;
			library[i - 1].judge = 1;             //���Ϊɾ��
			break;
		case 4:
			k = 0;                                                    //δ��ӹ�
			for (i = 0; i < count; i++)
			{
				if (library[i].judge == 1)
				{
					printf("�������\n");
					printf("����������");
					s_gets(library[i].title, MAXTITL);
					printf("��������:");
					s_gets(library[i].author, MAXAUTL);
					printf("����۸�:");
					scanf_s("%f", &library[i].value);
					while (getchar() != '\n')
						continue;
					library[i].judge = 0;               //���Ϊδɾ��
					k = 1;                             //����ӹ�
					break;
				}
			}
			if (k == 0)
			{
				if (count == 10)
					printf("�ļ�����\n");
				else
				{
					printf("�������\n");
					printf("��������:");
					s_gets(library[count].title, MAXTITL);
					printf("��������:");
					s_gets(library[count].author, MAXAUTL);
					printf("����۸�:");
					scanf_s("%f", &library[count].value);
					while (getchar() != '\n')
						continue;
					library[count++].judge = 0;
				}
			}
			break;
		}
		printf("1> �鿴���            2> ��������\n");
		printf("3> ɾ������            4> ��������\n");
		printf("5> �˳�������\n");
		scanf_s("%d", &c);
	}
	//���浽�ļ�
	if ((err = fopen_s(&fp, "aa.txt", "wb")) != 0)
	{
		fprintf(stderr, "�ļ���ʧ��");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < count; i++)
	{
		if (library[i].judge == 0)
			fwrite(&library[i], size, 1, fp);
	}
	fclose(fp);
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
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