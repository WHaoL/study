#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"

/*
�ӵ�һ���ַ���ʼɨ��
��������ͨ�ַ�ʱ���ԣ�
������������ʱѹ��ջ��
������������ʱ��ջ�е���ջ�����ţ�������ƥ��
ƥ��ɹ�������������һ���ַ�
ƥ��ʧ�ܣ�����ֹͣ��������
������
�ɹ�: �����ַ�ɨ����ϣ���ջΪ��
ʧ�ܣ�ƥ��ʧ�ܻ������ַ�ɨ����ϵ�ջ�ǿ�
*/

int isLeft(char ch)
{
	return ch == '(';
}

int isRight(char ch)
{
	return ch == ')';
}

//��ӡ����
void printError(char * str, char * errInfo, char *  pos)
{
	printf("����ԭ��%s\n", errInfo);

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
	char * str = "5+5*(6)+9/3*1)-(1+3(";  //������ûƥ��������
	//char * str = "5+5*(6)+9/3*1-(1+3("; //������ûƥ��������

	//char * str = "5+5*(6)+9/3*1-1+3"; //�޴�

	char * p = str;

	//��ʼ��ջ
	SeqStack stack = init_SeqStack();

	while (*p != '\0')
	{
		//����������� ��ջ
		if (isLeft(*p))
		{
			push_SeqStack(stack, p);
		}

		//�����������  ��ջ
		if (isRight(*p))
		{
			//���ջԪ�ظ��� > 0 ��ջ
			if (size_SeqStack(stack) > 0)
			{
				pop_SeqStack(stack);
			}
			else
			{
				//���ջΪ��ջ   ����ֹͣ��������
				printError(str, "������û��ƥ�䵽��Ӧ��������" ,p);
				break;
			}
		}
		//ָ��ƫ��
		p++;
	}


	//�ж�ջ�Ƿ�Ϊ�� ���Ϊ�� û��
	while (size_SeqStack(stack) > 0)
	{
		//�ǿ�ջ ���� ����ӡ������Ϣ
		printError(str, "������û��ƥ�䵽��Ӧ��������",top_SeqStack(stack) );
		//��ջ
		pop_SeqStack(stack);
	}

	//����ջ
	destroy_SeqStack(stack);
	stack = NULL;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}