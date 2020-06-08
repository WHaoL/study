#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

#define  WORD_NUM 15

void test01()
{

	//a  ~ z
	//�����ַ����� �������������Ӣ���ַ�

	//��ʼ���ַ����� һ��16��0
	char buf[WORD_NUM + 1] = { 0 };

	//�������Ӣ���ַ�
	for (int i = 0; i < WORD_NUM; i++)
	{
		buf[i] = rand()%26 + 'a';  //  97 + 0  ~  97 + 25    a ~ z 
	}
	printf("%s\n", buf);

	
	int count = 0;//ͳ����ȷ�ַ�
	int startTime = 0; //��ʼͳ�Ƶ�ʱ��
	int endTime = 0; //��ֹͳ�Ƶ�ʱ��


	//�û���������ַ�
	for (int i = 0; i < WORD_NUM;i++)
	{
		// getch���Բ�����س� ֱ��ȡ�ߵ�ch��  
		// getchar();  ��Ҫ���س� ��ȷ������
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
		else //������
		{
			printf("_");
		}
	}
	endTime = time(NULL);
	
	printf("\n");
	printf("��ȷ��Ϊ : %.2f%%\n", ((double)count / WORD_NUM * 100) );
	printf("��ʱ��%d��\n", endTime - startTime);
}

int main(){
	srand((size_t)time(NULL));

	test01();

	system("pause");
	return EXIT_SUCCESS;
}