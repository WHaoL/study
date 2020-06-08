#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//��̬����ṹ��
struct dynamicArray
{
	void ** addr; //ά���ڶ�����������ָ��

	int m_Capacity; //����

	int m_Size; //��С
};

//��ʼ������   ���� ��ʼ����
struct dynamicArray * init_dynamicArray(int capacity);


//����Ԫ��  ����1  ����ָ��   ����2  ����λ��   ����3 �����������
void insert_dynamicArray(struct dynamicArray * arr, int pos, void * data);


//��������
void foreach_dynamicArray(struct dynamicArray *arr, void(*myPrint)(void*));


//ɾ��Ԫ��  --- ��λ��ɾ��Ԫ��
void removeByPos_dynamicArray(struct dynamicArray *arr, int pos);

//ɾ��Ԫ��  ��ֵ��ʽɾ��
void removeByValue_dynamicArray(struct dynamicArray *arr, void * data, int(*myCompare)(void*, void*));

//��������
void destroy_dynamicArray(struct dynamicArray *arr);


