#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

	//想输出 \  利用两个\

	//常用
	// \n  换行
	// \\  输出一个\
	// \r 将光标移动到当前行起始位置
	// \t 水平制表符   tab建
	//  %输出  %%

	//printf("哈\\哈哈\n");
	//printf("\a"); //警告提示音
	
	//printf("abc\rdef\n");
	//printf("aaa\tbbb\n");
	printf("90%%\n");

	system("pause");
	return EXIT_SUCCESS;
}