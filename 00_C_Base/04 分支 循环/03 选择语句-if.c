#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//���� if���
void test01()
{
	//������������ ����600�֣���Ϊ����һ����ѧ���������
	int score = 0;

	printf("������һ��������\n");

	scanf("%d", &score);

	printf("������ķ���Ϊ��%d\n", score);

	//�﷨�� if������������{ ��������������ִ�е���� }
	if (score > 600)
	{
		printf("������һ����ѧ��\n");
	}
}

//����if���
void test02()
{
	//������������ ����600�֣���Ϊ����һ����ѧ�������û�п���һ����Ҳ���
	int score = 0;

	printf("������һ��������\n");

	scanf("%d", &score);

	printf("������ķ���Ϊ��%d\n", score);

	if (score > 600)
	{
		printf("������һ����ѧ��\n");
	}
	else //δ��������  ���������
	{
		printf("δ����һ����ѧ\n");
	}
}

//������if���
void test03()
{
	//������������ ����600�֣���Ϊ����һ����ѧ,����500 �����϶���������400 ����������С�ڵ���400��û���ϱ���
	int score = 0;

	printf("������һ��������\n");

	scanf("%d", &score);

	printf("������ķ���Ϊ��%d\n", score);


	if (score > 600)
	{
		printf("������һ����ѧ��\n");
	}
	else if (score > 500)
	{
		printf("�����˶�����ѧ��\n");
	}
	else if (score > 400)
	{
		printf("������������ѧ��\n");
	}
	else
	{
		printf("û�п��ϱ��ƣ�\n");
	}
}

//if��� Ƕ�� if���
void test04()
{
	int score = 0;

	printf("������һ��������\n");

	scanf("%d", &score);

	printf("������ķ���Ϊ��%d\n", score);

	//����һ���ˣ�����Ǵ���700�֣���Ϊ���ϱ��󣬴���650�������廪�����࣬�����˴�
	if (score > 600)
	{
		printf("������һ����ѧ��\n");

		if (score > 700)
		{
			printf("��ϲ�㿼���˱���\n");
		}
		else if (score > 650)
		{
			printf("��ϲ�㿼�����廪��\n");
		}
		else
		{
			printf("��ϲ�㿼�����˴�\n");
		}

	}
	else if (score > 500)
	{
		printf("�����˶�����ѧ��\n");
	}
	else if (score > 400)
	{
		printf("������������ѧ��\n");
	}
	else
	{
		printf("û�п��ϱ��ƣ�\n");
	}

}


//if����ע������
void test05()
{
	//1����Ҫ��if���ĺ���� �ֺ�;
	int a = 10;
	int b = 20;
	//if (a > b); //�������ֺţ�����Ĵ���϶���ִ��
	//{
	//	printf("a > b\n");
	//}

	//2��if���ʵ�������������{},ֻ��ʶ�������һ�д���
	//if (a > b)
	//	printf("a > b\n");
	//printf("a > b\n");


	//3�����ԱȲ�����ʱ�򣬲�Ҫд�� =  �������� ==
	int num = 5;
	if (num = 10) //error ��Ҫд�� = 
	{
		printf("num == 10\n");
	}
	else
	{
		printf("num != 10\n");
	}

}

//��ֻС�������
void test06()
{
	//1��������ֻС������ ���� 
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	//2���û���������ֻ�������
	printf("���С��A���ظ�ֵ��\n");
	scanf("%d", &num1);

	printf("���С��B���ظ�ֵ��\n");
	scanf("%d", &num2);

	printf("���С��C���ظ�ֵ��\n");
	scanf("%d", &num3);

	printf("С��A������Ϊ:%d\n", num1);
	printf("С��B������Ϊ:%d\n", num2);
	printf("С��C������Ϊ:%d\n", num3);

	//3���Ա� ˭����
	if (num1 > num2) //A  ��  B ��
	{
		if (num1 > num3) // A ����
		{
			printf("С��A����,����Ϊ%d��\n", num1);
		}
		else //C����
		{
			printf("С��C����,����Ϊ%d��\n", num3);
		}
	}
	else  //B �� A ��
	{
		if (num2 > num3) // B����
		{
			printf("С��B����,����Ϊ%d��\n", num2);
		}
		else //C����
		{
			printf("С��C����,����Ϊ%d��\n", num3);
		}
	}

}

int main(){

	test04();

	system("pause");
	return EXIT_SUCCESS;
}