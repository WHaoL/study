#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "point.h"

//Բ��
class Circle
{
public:
	//���� �뾶  
	void setR(int r);
	
	//���� Բ��
	void setCenter(Point center);

	//��ȡ �뾶 Բ��
	int getR();

	Point getCenter();

	//ͨ����Ա�����жϵ��Բ��ϵ
	void isInCircleByClass(Point &p);


private:
	//�뾶
	int m_R;
	//Բ��
	Point m_Center;
};
