#pragma  once  //��ֹͷ�ļ��ظ�����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����������ȫ�ֱ�������


//��������
void allocateSpace(int ** arr, int num);

//��������Ԫ��
void setArray(int * arr , int num);

//��ӡ���� 
void printArray(int * arr, int num);

//���������������
void sortArray(int * arr, int num);

//��ȡ����ƽ��ֵ
int getAvgArray(int * arr, int num);

//��ȡ�������ֵ
int getMax(int * arr, int num);

//��ȡ������Сֵ
int getMin(int * arr, int num);

//��ȡ�����ܺ�
int getSum(int * arr, int num);

//�ͷ�����
void freeArray(int ** arr);