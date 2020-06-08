#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"

/*
从第一个字符开始扫描
当遇见普通字符时忽略，
当遇见左括号时压入栈中
当遇见右括号时从栈中弹出栈顶符号，并进行匹配
匹配成功：继续读入下一个字符
匹配失败：立即停止，并报错
结束：
成功: 所有字符扫描完毕，且栈为空
失败：匹配失败或所有字符扫描完毕但栈非空
*/

int isLeft(char ch)
{
	return ch == '(';
}

int isRight(char ch)
{
	return ch == ')';
}

//打印错误
void printError(char * str, char * errInfo, char *  pos)
{
	printf("错误原因：%s\n", errInfo);

	printf("%s\n", str);

	int num = pos - str;
	for (int i = 0; i < num; i++)
	{
		printf(" ");
	}
	printf("A\n");
}

void test01()
{
	char * str = "5+5*(6)+9/3*1)-(1+3(";  //右括号没匹配左括号
	//char * str = "5+5*(6)+9/3*1-(1+3("; //左括号没匹配右括号

	//char * str = "5+5*(6)+9/3*1-1+3"; //无错

	char * p = str;

	//初始化栈
	SeqStack stack = init_SeqStack();

	while (*p != '\0')
	{
		//如果是左括号 入栈
		if (isLeft(*p))
		{
			push_SeqStack(stack, p);
		}

		//如果是右括号  出栈
		if (isRight(*p))
		{
			//如果栈元素个数 > 0 出栈
			if (size_SeqStack(stack) > 0)
			{
				pop_SeqStack(stack);
			}
			else
			{
				//如果栈为空栈   立即停止，并报错
				printError(str, "右括号没有匹配到对应的左括号" ,p);
				break;
			}
		}
		//指针偏移
		p++;
	}


	//判断栈是否为空 如果为空 没错
	while (size_SeqStack(stack) > 0)
	{
		//非空栈 出错 ，打印错误信息
		printError(str, "左括号没有匹配到对应的右括号",top_SeqStack(stack) );
		//出栈
		pop_SeqStack(stack);
	}

	//销毁栈
	destroy_SeqStack(stack);
	stack = NULL;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}