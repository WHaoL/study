#pragma once
#include <iostream>
using namespace std;

//���������Ļ���
class Weapon
{
public:

	//��ȡ�����˺�
	virtual int getBaseDamage() = 0;
	//����Ч�� ����ֵ����0 ��������
	virtual int getCrit() = 0;
	//��ȡ��Ѫ ����ֵ����0 ������Ѫ
	virtual int getSuckBlood() = 0;
	//����Ч�� ����true �������
	virtual int getFrozen() = 0;

	//��������
	virtual bool isTrigger(int rate) = 0;

	//��������
	int baseDamage;
	//��������
	string weaponName;
	//��������ϵ��
	int critPlus;
	//������
	int critRate;
	//��Ѫϵ��
	int suckPlus;
	//��Ѫ��
	int suckRate;
	//������
	int forzenRate;

};