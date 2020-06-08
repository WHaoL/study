#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

#define  WORD_NUM 15

void test01()
{

	//a  ~ z
	//创建字符数组 保存随机产生的英文字符

	//初始化字符数组 一共16个0
	char buf[WORD_NUM + 1] = { 0 };

	//产生随机英文字符
	for (int i = 0; i < WORD_NUM; i++)
	{
		buf[i] = rand()%26 + 'a';  //  97 + 0  ~  97 + 25    a ~ z 
	}
	printf("%s\n", buf);

	
	int count = 0;//统计正确字符
	int startTime = 0; //开始统计的时间
	int endTime = 0; //截止统计的时间


	//用户输入产生字符
	for (int i = 0; i < WORD_NUM;i++)
	{
		// getch可以不输入回车 直接取走到ch中  
		// getchar();  需要按回车 才确认输入
		char ch = _getch();  

		if (i == 0)
		{
			startTime = time(NULL);
		}
		if (ch == buf[i])
		{
			count++;
			printf("%c", ch);
		}
		else //打错情况
		{
			printf("_");
		}
	}
	endTime = time(NULL);
	
	printf("\n");
	printf("正确率为 : %.2f%%\n", ((double)count / WORD_NUM * 100) );
	printf("用时：%d秒\n", endTime - startTime);
}

int main(){
	srand((size_t)time(NULL));

	test01();

	system("pause");
	return EXIT_SUCCESS;
}