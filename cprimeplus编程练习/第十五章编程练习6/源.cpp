#include<stdio.h>
#define LEFT 0
#define CENTER 1
#define RIGHT 2
#define ON 1
#define OFF 0
struct font {
	unsigned int fontl: 8;
	unsigned int size : 7;
	unsigned int : 1;
	unsigned int alignment : 2;
	unsigned int bold : 1;
	unsigned int italic : 1;
	unsigned int : 4;
	unsigned int underline : 1;
};
void menu(struct font m);

int main(void)
{
	char c, a;
	unsigned int d;
	struct font box = { 1,12,LEFT,OFF,OFF,OFF };
	
	menu(box);
	scanf_s("%c", &c, 1);
	getchar();
	while (c != 'q')
	{
		switch (c)
		{
		case 'f':printf("Enter font ID (0-255):");
			scanf_s("%u", &d);
			box.fontl = d;
			getchar();
			break;
		case 's':printf("Enter font size (0-127):");
			scanf_s("%u", &d);
			box.size = d;
			getchar();
			break;
		case 'a':printf("Select alignment:\n");
			printf("l)left c)center r)right\n");
			scanf_s("%c", &a, 1);
			getchar();
			if (a == 'l')
				box.alignment = LEFT;
			else if (a == 'c')
				box.alignment = CENTER;
			else
				box.alignment = RIGHT;
			break;
		case 'b':printf("\n");
			box.bold ^= 1;
			break;
		case 'i':printf("\n");
			box.italic ^= 1;
			break;
		case 'u':printf("\n");
			box.underline ^= 1;
			break;
		}
		menu(box);
		scanf_s("%c", &c, 1);
	}
}

void menu(struct font m)
{
	printf("ID SIZE ALIGNMENT   B   I   U\n");
	printf("%2u%5u", m.fontl, m.size);
	if (m.alignment == LEFT)
		printf("   left     ");
	else if (m.alignment == CENTER)
		printf("   center   ");
	else
		printf("   right    ");
	printf("%s ", m.bold == ON ? "on" : "off");
	printf("%s ", m.italic == ON ? "on" : "off");
	printf("%s \n\n\n", m.underline == ON ? "on" : "off");

	printf("f)change font   s)change size    a)change alignment\n");
	printf("b)toggle bold   i)toggle italic  u)toggle underline\n");
	printf("q)quit\n");
}