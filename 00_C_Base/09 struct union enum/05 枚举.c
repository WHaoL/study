#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//ö���е�ÿ��ֵ ��0��ʼ ���ε���
enum POKER
{
	HONGTAO , HEITAO = 3, MEIHUA = 7,  FANGPIAN = 7
};

void test01()
{
	enum POKER poker;
	poker = MEIHUA;
	printf("%d\n", poker);

	printf("hongtao = %d\n", HONGTAO); // 0
	printf("heitao = %d\n", HEITAO);   //3
	printf("meihua = %d\n", MEIHUA);   //7
	printf("fangpian = %d\n", FANGPIAN); // 7

	//HONGTAO = 1; // error ö��Ԫ�ص�ֵ �ǲ������޸ĵ� ������ #define  HONGTAO 0
}

//BOOL ������������ ��������ͼٵ�һ�����ͣ���C��û�У������ģ�³�����������enum
// �� ---  TRUE     ��  --- FALSE  
enum  BOOL
{
	FALSE, //��
	TRUE   //��
};

void test02()
{
	enum BOOL flag;
	//flag = FALSE;
	flag = TRUE;
	if (flag == TRUE)
	{
		printf("��־flagΪ��\n");
	}
	else
	{
		printf("��־flagΪ��\n");
	}
}

enum 
{
	WIDTH = 1000,
	HEIGHT =1000
};
void test03()
{
	printf("ǽ�Ŀ��Ϊ��%d\n", WIDTH);
	printf("ǽ�ĸ߶�Ϊ��%d\n", HEIGHT);
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}