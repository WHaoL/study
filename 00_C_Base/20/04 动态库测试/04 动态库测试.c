#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#pragma comment(lib,"./mydll.lib")


int main(){
	
	printf("100 - 70 = %d\n", mySub(100, 70));


	system("pause");
	return EXIT_SUCCESS;
}