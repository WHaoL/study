#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��ά���鶨��
void test01()
{
	//��ʽ1
	//Ԫ����������  ������ ����������������
	int arr[2][3];

	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;

	//printf("%d\n", arr[0][0]);
	//printf("%d\n", arr[0][1]);
	//printf("%d\n", arr[0][2]);

	//���ѭ��
	//for (int i = 0; i < 2; i++)
	//{
	//	//�ڲ�ѭ��
	//	for (int j = 0; j < 3; j++)
	//	{
	//		printf("%d ", arr[i][j]);
	//	}
	//	printf("\n");
	//}

	//��ʽ2  �Ƽ�
	int arr2[2][3] = { 
		{ 1, 2, 3 }, 
		{ 4, 5, 6 },  //���һ�н�β,��ѡ���
	};
	//for (int i = 0; i < 2; i++)
	//{
	//	//�ڲ�ѭ��
	//	for (int j = 0; j < 3; j++)
	//	{
	//		printf("%d ", arr2[i][j]);
	//	}
	//	printf("\n");
	//}

	//��ʽ3 
	int arr3[2][3] = { 1, 2, 3, 4, 5, 6 }; //����Ҳ��һ��һά���飬��ַҲ������


	//��ʽ4
	int arr4[][3] = { 1, 2, 3, 4, 5, 6 ,7};  //��������ʡ��
	for (int i = 0; i < 3; i++)
	{
		//�ڲ�ѭ��
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr4[i][j]);
		}
		printf("\n");
	}
}

//��ά����������
void test02()
{
	int arr[2][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },  
	};

	//���Բ鿴��������ռ���ڴ�ռ��С
	printf("��ά����ռ�ÿռ�Ϊ%d\n", sizeof(arr)); //24
	printf("��ά����ÿ��ռ�ÿռ�Ϊ%d\n", sizeof(arr[0])); //12
	printf("��ά����ÿ��Ԫ��ռ�ÿռ�Ϊ%d\n", sizeof(arr[0][0])); // 4

	//��ά���� ����  ����
	printf("��ά��������:%d\n", sizeof(arr) / sizeof(arr[0]));
	printf("��ά��������:%d\n", sizeof(arr[0])/sizeof(arr[0][0]));

	//���Բ鿴��ά�����׵�ַ
	printf("��ά�����׵�ַ %d\n", arr);
	printf("��ά�����һ�е�ַ %d\n", arr[0]);
	printf("��ά����ڶ��е�ַ %d\n", arr[1]);

	printf("��һ��Ԫ�صĵ�ַ:%d\n", &arr[0][0]);
	printf("�ڶ���Ԫ�صĵ�ַ:%d\n", &arr[0][1]);
}

//��ά����Ӧ�ð��� ���ܺͳɼ�
void test03()
{
	int scores[3][3] =
	{
		{ 100, 100, 100 },  //��һ���˿��Գɼ�  
		{ 90, 50, 80 },  //�ڶ����˿��Գɼ� 
		{ 70, 80, 90 },  //�������˿��Գɼ� 
	};

	//���ô�����ʾÿ���˵ĳɼ����ܺ�

	char* names[3] = {"����", "����", "����"};

	int row = sizeof(scores) / sizeof(scores[0]);
	int col = sizeof(scores[0]) / sizeof(scores[0][0]);
	for (int i = 0; i <row; i++)
	{
		int sum = 0;
		for (int j = 0; j < col; j++)
		{
			sum += scores[i][j];
			printf("%d ", scores[i][j]);

		}
		printf("\n");
		printf("��%d��ͬѧ%s���ܷ�Ϊ %d\n", i + 1, names[i], sum);
		printf("��%d��ͬѧ%s��ƽ����Ϊ %d\n", i + 1,names[i], sum / col);
	}


}

int main(){

	test03();

	system("pause");
	return EXIT_SUCCESS;
}