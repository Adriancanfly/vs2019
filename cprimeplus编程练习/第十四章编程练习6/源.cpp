#include<stdio.h>
#include<stdlib.h>

struct number {
	int a;
	char first[15];
	char last[15];
	int time;
	int beat;
	int run;
	int ibs;
	double rate;
};
//将结构成员初始化为零
void initStruct(struct number* s, int n);
//获取一行数据并返回球员号
int get_a(FILE*fp,struct number* s);
//将数据存入结构
void to_struct(struct number* t1, struct number* t2);
//计算安打率
void calculate(struct number* s);
//显示
void print(struct number* s);

int main(void)
{
	FILE* fp;
	errno_t err;
	struct number a[19];
	struct number b;
	int i, num;
	
	if ((err = fopen_s(&fp, "aa.txt", "r")) != 0)
	{
		fprintf(stderr, "文件打开失败");
		exit(EXIT_FAILURE);
	}
	initStruct(a, 19);
	while (feof(fp) == 0)
	{
		num = get_a(fp, &b);
		if (feof(fp) == 0)
			to_struct(&a[num], &b);
	}
	for (i = 0; i < 19; i++)
		calculate(&a[i]);
	
	for (i = 0; i < 19; i++)
		print(&a[i]);

	fclose(fp);
	return 0;
}
void initStruct(struct number* s, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		s[i].a = 0;
		s[i].first[0] = '\0';
		s[i].last[0] = '\0';
		s[i].time = 0;
		s[i].beat = 0;
		s[i].run = 0;
		s[i].ibs = 0;
		s[i].rate = 0;
	}
}
int get_a(FILE*fp,struct number* st)
{
	int num;
	fscanf_s(fp, "%d", &st->a);
	num = st->a;
	fscanf_s(fp, "%s", st->first, 15);
	fscanf_s(fp, "%s", st->last, 15);
	fscanf_s(fp, "%d", &st->time);
	fscanf_s(fp, "%d", &st->beat);
	fscanf_s(fp, "%d", &st->run);
	fscanf_s(fp, "%d", &st->ibs);

	return num;
}
void to_struct(struct number* t1, struct number* t2)
{
	if (t1->first[0] == '\0')
	{
		*t1 = *t2;
	}
	else
	{
		t1->time += t2->time;
		t1->beat += t2->beat;
		t1->run += t2->run;
		t1->ibs += t2->ibs;
	}
}
void calculate(struct number* s)
{
	if (s->first[0] != '\0')
		s->rate = (double)(s->beat) / (s->time);
}
void print(struct number* s)
{
	if (s->first[0] != '\0')
		printf("%d)\t%s\t%s\t%d\t%d\t%d\t%d\t%lf\n", s->a, s->first, s->last,
			s->time, s->beat, s->run, s->ibs, s->rate);
}