#pragma once
#include <iostream>
using namespace std;
#include "weapon.h"
#include "monster.h"

class Monster;
//Ӣ����
class Hero
{
public:
//��Ϊ
	//Ӣ�۵��вι���
	Hero(int heroId);

	//Ӣ�۵Ĺ���
	void Attack(Monster * monster);

	//װ������
	void EquipWeapon(Weapon * weapon);

//����
	//Ѫ��
	int heroHp;
	//������
	int heroAtk;
	//������
	int heroDef;
	//����
	string heroName;
	//���
	string heroInfo;
	//����ָ��
	Weapon * weapon;
};