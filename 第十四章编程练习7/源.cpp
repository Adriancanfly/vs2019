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
	int judge;           //判断是否被删除
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
		fprintf(stderr, "文件打开失败!");
		exit(EXIT_FAILURE);
	}

	rewind(fp);

	while (count < MAXBKS && fread(&library[count], size, 1, fp))
		count++;
	fclose(fp);
	if (count == 0)
	{
		printf("没有任何书，请先添加!(双击结束添加）\n");
		printf("添加书名:");
		while (s_gets(library[count].title, MAXTITL) != NULL && count < MAXBKS && library[count].title[0] != '\0')
		{
			printf("输入作者:");
			s_gets(library[count].author, MAXTITL);
			printf("输入价格:");
			scanf_s("%f", &library[count++].value);
			while (getchar() != '\n')
				continue;
			if (count == MAXBKS)
				printf("文件已满！\n");
			else
				printf("添加书名（双击结束添加）:");
		}
	}
	for (i = 0; i < count; i++)
	{
		library[i].judge = 0;                //设置所有数据为未删除
	}
	printf("1> 查看书库            2> 更改内容\n");
	printf("3> 删除内容            4> 增添内容\n");
	printf("5> 退出并保存\n");
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
					printf("被删除\n");
					h++;
				}
			}
			printf("共有%d本书\n", count-h);
			break;
		case 2: printf("要修改那本书?\n");
			for (i = 0; i < count; i++)
			{
				if (library[i].judge == 0)
					printf("%d) %s by %s ,value: %f\n", i + 1, library[i].title, library[i].author, library[i].value);
				else
					printf("被删除\n");
			}
			printf("输入序号:");
			scanf_s("%d", &i);
			while (getchar() != '\n')
				continue;
			printf("输入书名:");
			s_gets(library[i - 1].title, MAXTITL);
			printf("输入作者:");
			s_gets(library[i - 1].author, MAXAUTL);
			printf("输入价格:");
			scanf_s("%f", &library[i - 1].value);
			while (getchar() != '\n')
				continue;
			library[i - 1].judge = 0;                        //若修改了被删除的数据，将其标记为未删除。
			break;
		case 3: printf("要删除那个数据?\n");
			for (i = 0; i < count; i++)
			{
				if (library[i].judge == 0)
					printf("%d) %s by %s,value: %f\n", i + 1, library[i].title, library[i].author, library[i].value);
				else
					printf("被删除\n");
			}
			printf("输入序号:");
			scanf_s("%d", &i);
			while (getchar() != '\n')
				continue;
			library[i - 1].judge = 1;             //标记为删除
			break;
		case 4:
			k = 0;                                                    //未添加过
			for (i = 0; i < count; i++)
			{
				if (library[i].judge == 1)
				{
					printf("添加内容\n");
					printf("输入书名：");
					s_gets(library[i].title, MAXTITL);
					printf("输入作者:");
					s_gets(library[i].author, MAXAUTL);
					printf("输入价格:");
					scanf_s("%f", &library[i].value);
					while (getchar() != '\n')
						continue;
					library[i].judge = 0;               //标记为未删除
					k = 1;                             //已添加过
					break;
				}
			}
			if (k == 0)
			{
				if (count == 10)
					printf("文件已满\n");
				else
				{
					printf("添加内容\n");
					printf("输入书名:");
					s_gets(library[count].title, MAXTITL);
					printf("输入作者:");
					s_gets(library[count].author, MAXAUTL);
					printf("输入价格:");
					scanf_s("%f", &library[count].value);
					while (getchar() != '\n')
						continue;
					library[count++].judge = 0;
				}
			}
			break;
		}
		printf("1> 查看书库            2> 更改内容\n");
		printf("3> 删除内容            4> 增添内容\n");
		printf("5> 退出并保存\n");
		scanf_s("%d", &c);
	}
	//保存到文件
	if ((err = fopen_s(&fp, "aa.txt", "wb")) != 0)
	{
		fprintf(stderr, "文件打开失败");
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