#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��������
void setCharArray(char * arr ,int num)
{
	printf("������һ���ַ���\n");

	fgets(arr, num, stdin); //stdin��׼�����豸 ����
}

//ͳ���ַ����� �Լ�ʵ��
int myStrlen(char * arr)
{
	//hello world\0\0\0\0
	int count = 0; //��¼�ַ����� 

	while (arr[count] != '\0')
	{
		count++;
	}

	return count;

	//�򻯰汾 
	//while (arr[count++]){}
	//return count - 1;
}


//�ı��ַ����飬��дתСд��Сдת��д
void changeArray(char *arr)
{
	int index = 0;
	while ( arr[index] != '\0')
	{
		//printf("%c", arr[index]);
		if (arr[index] >= 'a' && arr[index] <= 'z')
		{
			arr[index] = arr[index] - ('a' - 'A');
		}
		else if (arr[index] >= 'A' && arr[index] <= 'Z')
		{
			arr[index] = arr[index] + ('a' - 'A');
		}
		index++;
	}
}

void test01()
{
	char buf[1024] = { 0 };

	//��������
	setCharArray(buf,sizeof(buf));

	//hello world\n\0\0\0
	buf[strlen(buf) - 1] = '\0'; //��\n���ַ���Ϊ\0

	//��ӡ���
	printf("%s\n", buf);

	//ͳ���ַ�������  strlen
	int count = myStrlen(buf);
	printf("count = %d\n", count);
	printf("count = %d\n", strlen(buf));

	//�ַ�����Сдת��  
	//Сд ת ��д     ��д ת Сд
	changeArray(buf);
	printf("ת����Ľ��Ϊ\n");
	printf("%s\n", buf);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}