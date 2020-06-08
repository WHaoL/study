#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

	extern const int g_a; //告诉编译器 在其他文件中有g_a
	printf("g_a = %d\n", g_a);

	system("pause");
	return EXIT_SUCCESS;
}