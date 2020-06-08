#include "dynamicArray.h"

//��ʼ������   ���� ��ʼ����
struct dynamicArray * init_dynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	//�����ڴ�ռ�
	struct dynamicArray * arr = malloc(sizeof(struct dynamicArray));

	if (arr == NULL)
	{
		return NULL;
	}

	//��ʼ������
	arr->addr = malloc(sizeof(void *)* capacity);
	memset(arr->addr, 0, sizeof(void *)* capacity);
	arr->m_Capacity = capacity;

	arr->m_Size = 0;

	return arr;
}


//����Ԫ��  ����1  ����ָ��   ����2  ����λ��   ����3 �����������
void insert_dynamicArray(struct dynamicArray * arr, int pos, void * data)
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos < 0 || pos > arr->m_Size)
	{
		//��Чλ�� ǿ��β��
		pos = arr->m_Size;
	}

	//�ж������Ƿ��Ѿ�����
	if (arr->m_Size == arr->m_Capacity)
	{
		//1��������������С
		int newCapacity = arr->m_Capacity * 2;

		//2�������¿ռ�
		void ** newSpace = malloc(sizeof(void *)* newCapacity);

		//3����ԭ�пռ��µ����ݿ������¿ռ���
		memcpy(newSpace, arr->addr, sizeof(void *)* arr->m_Capacity);

		//4���ͷ�ԭ�пռ�
		free(arr->addr);

		//5������ָ���ָ��
		arr->addr = newSpace;

		//6����������
		arr->m_Capacity = newCapacity;
	}


	//��������
	for (int i = arr->m_Size - 1; i >= pos; i--)
	{
		//����ƶ�����
		arr->addr[i + 1] = arr->addr[i];
	}
	//����Ԫ�ز��뵽ָ��λ����
	arr->addr[pos] = data;

	//���´�С
	arr->m_Size++;
}

//��������
void foreach_dynamicArray(struct dynamicArray *arr, void(*myPrint)(void*))
{
	for (int i = 0; i < arr->m_Size; i++)
	{
		//arr->addr[i]ÿ�����ݵ��׵�ַ
		myPrint(arr->addr[i]);
	}
}

//ɾ��Ԫ��  --- ��λ��ɾ��Ԫ��
void removeByPos_dynamicArray(struct dynamicArray *arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}

	//��Ч��λ�� ֱ��return
	if (pos < 0 || pos > arr->m_Size - 1)
	{
		return;
	}

	for (int i = pos; i < arr->m_Size - 1; i++)
	{
		arr->addr[i] = arr->addr[i + 1];
	}

	//���������С
	arr->m_Size--;
}

//ɾ��Ԫ��  ��ֵ��ʽɾ��
void removeByValue_dynamicArray(struct dynamicArray *arr, void * data, int(*myCompare)(void*, void*))
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (myCompare == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->m_Size; i++)
	{
		//if (arr->addr[i] == data )
		if (myCompare(arr->addr[i], data))
		{
			removeByPos_dynamicArray(arr, i);
			break;
		}
	}

}
//��������
void destroy_dynamicArray(struct dynamicArray *arr)
{
	if (arr == NULL)
	{
		return;
	}

	if (arr->addr != NULL)
	{
		free(arr->addr);
		arr->addr = NULL;
	}

	free(arr);
	arr = NULL;
}
