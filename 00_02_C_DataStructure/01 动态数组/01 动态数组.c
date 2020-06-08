#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dynamicArray.h"

////��̬����ṹ��
//struct dynamicArray
//{
//	void ** addr; //ά���ڶ�����������ָ��
//
//	int m_Capacity; //����
//
//	int m_Size; //��С
//};
//
////��ʼ������   ���� ��ʼ����
//struct dynamicArray * init_dynamicArray(int capacity)
//{
//	if (capacity <= 0)
//	{
//		return NULL;
//	}
//
//	//�����ڴ�ռ�
//	struct dynamicArray * arr = malloc(sizeof(struct dynamicArray));
//
//	if (arr== NULL)
//	{
//		return NULL;
//	}
//	
//	//��ʼ������
//	arr->addr = malloc(sizeof(void *)* capacity);
//	memset(arr->addr, 0, sizeof(void *)* capacity);
//	arr->m_Capacity = capacity;
//
//	arr->m_Size = 0;
//
//	return arr;
//}
//
//
////����Ԫ��  ����1  ����ָ��   ����2  ����λ��   ����3 �����������
//void insert_dynamicArray(struct dynamicArray * arr, int pos, void * data)
//{
//	if (arr == NULL)
//	{
//		return;
//	}
//	if (data == NULL)
//	{
//		return;
//	}
//	if (pos < 0 || pos > arr->m_Size )
//	{
//		//��Чλ�� ǿ��β��
//		pos = arr->m_Size;
//	}
//
//	//�ж������Ƿ��Ѿ�����
//	if (arr->m_Size == arr->m_Capacity)
//	{
//		//1��������������С
//		int newCapacity = arr->m_Capacity * 2;
//
//		//2�������¿ռ�
//		void ** newSpace  = malloc(sizeof(void *)* newCapacity);
//
//		//3����ԭ�пռ��µ����ݿ������¿ռ���
//		memcpy(newSpace, arr->addr, sizeof(void *)* arr->m_Capacity);
//
//		//4���ͷ�ԭ�пռ�
//		free(arr->addr);
//
//		//5������ָ���ָ��
//		arr->addr = newSpace;
//
//		//6����������
//		arr->m_Capacity = newCapacity;
//	}
//
//
//	//��������
//	for (int i = arr->m_Size - 1; i >= pos; i--)
//	{
//		//����ƶ�����
//		arr->addr[i + 1] = arr->addr[i];
//	}
//	//����Ԫ�ز��뵽ָ��λ����
//	arr->addr[pos] = data;
//
//	//���´�С
//	arr->m_Size++;
//}
//
////��������
//void foreach_dynamicArray(struct dynamicArray *arr , void(*myPrint)(void*))
//{
//	for (int i = 0; i < arr->m_Size;i++)
//	{
//		//arr->addr[i]ÿ�����ݵ��׵�ַ
//		myPrint(arr->addr[i]);
//	}
//}
//
////ɾ��Ԫ��  --- ��λ��ɾ��Ԫ��
//void removeByPos_dynamicArray(struct dynamicArray *arr, int pos)
//{
//	if (arr == NULL)
//	{
//		return;
//	}
//
//	//��Ч��λ�� ֱ��return
//	if (pos < 0 || pos > arr->m_Size - 1)
//	{
//		return;
//	}
//
//	for (int i = pos; i < arr->m_Size-1;i++)
//	{
//		arr->addr[i] = arr->addr[i + 1];
//	}
//
//	//���������С
//	arr->m_Size--;
//}
//
////ɾ��Ԫ��  ��ֵ��ʽɾ��
//void removeByValue_dynamicArray(struct dynamicArray *arr, void * data  , int(*myCompare)(void*,void* ) )
//{
//	if (arr == NULL)
//	{
//		return;
//	}
//	if (data == NULL)
//	{
//		return;
//	}
//	if (myCompare == NULL)
//	{
//		return;
//	}
//
//	for (int i = 0; i < arr->m_Size;i++)
//	{
//		//if (arr->addr[i] == data )
//		if (myCompare(arr->addr[i],data))
//		{
//			removeByPos_dynamicArray(arr, i);
//			break;
//		}
//	}
//
//}
////��������
//void destroy_dynamicArray(struct dynamicArray *arr)
//{
//	if (arr== NULL)
//	{
//		return;
//	}
//
//	if (arr->addr != NULL)
//	{
//		free(arr->addr);
//		arr->addr = NULL;
//	}
//
//	free(arr);
//	arr = NULL;
//}






//���Զ�̬����
struct Person
{
	char name[64];
	int age;
};

void printPerson(void * data)
{
	struct Person * p = data;
	printf("������%s  ���䣺%d\n", p->name, p->age);
}

int comparePerson(void * data1,void * data2)
{
	struct Person * p1 = data1;
	struct Person * p2 = data2;

	//if ( strcmp( p1->name ,  p2->name) == 0 && p1->age == p2->age)
	//{
	//	return 1;
	//}
	//return 0;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

int main(){

	//��ʼ������
	struct dynamicArray * arr = init_dynamicArray(5);

	struct Person p1 = { "����", 19 };
	struct Person p2 = { "槼�", 20 };
	struct Person p3 = { "³��", 18 };
	struct Person p4 = { "�ŷ�", 22 };
	struct Person p5 = { "�ݼ�", 21 };
	struct Person p6 = { "�缧", 23 };

	printf("��������ǰ -- ���������:%d\n", arr->m_Capacity);
	//��������
	insert_dynamicArray(arr, 0, &p1);
	insert_dynamicArray(arr, 0, &p2);
	insert_dynamicArray(arr, 0, &p3);
	insert_dynamicArray(arr, 1, &p4);
	insert_dynamicArray(arr, -1, &p5);
	insert_dynamicArray(arr, 100, &p6);

	//arr->m_Capacity = 0;
	//arr->m_Size = -1;
	//arr->addr = NULL;

	printf("�������ݺ� -- ���������:%d\n", arr->m_Capacity);
	// ³�� �ŷ� 槼� ���� �ݼ�  �缧

	//��������
	foreach_dynamicArray(arr, printPerson);

	//ɾ��Ԫ��  ɾ����
	removeByPos_dynamicArray(arr, 3);
	printf("-----------------------------\n");
	printf("ɾ��������������Ϊ\n");
	foreach_dynamicArray(arr, printPerson);

	//ɾ��Ԫ��  ɾ�ŷ�
	struct Person p = { "�ŷ�", 22 };
	removeByValue_dynamicArray(arr, &p, comparePerson);

	printf("-----------------------------\n");
	printf("ɾ���ŷɺ�������Ϊ\n");
	foreach_dynamicArray(arr, printPerson);


	//��������
	destroy_dynamicArray(arr);

	system("pause");
	return EXIT_SUCCESS;
}