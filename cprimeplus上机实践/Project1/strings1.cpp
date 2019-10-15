// strings1.c
#include<stdio.h>
#define MSG "I am a symbolic string constant."
#define MAXLENGTH 81
int main(void)
{
	char words[MAXLENGTH] = "I am a string in an array.";
	const char* pt1 = "Something is pointing at me.";
	puts(MSG);
	puts(words);
	puts(pt1);
	words[8] = 'p';
	puts(words);

	return 0;
}
//puts()函数只用于打印字符串！并且会在字符串末尾自动加上换行符。