#pragma once
#include <iostream>
using namespace std;
#include "hero.h"

class Hero;
class Monster
{
public:
	//�вι��� 
	Monster(int monsterId);
	//���﹥������ʵ��
	void Attack(Hero *hero);
public:
	string monsterName; //��������
	int monsterHp;  //����Ѫ��
	int monsterAtk;  //���﹥����
	int monsterDef;  //���������
	bool isFrozen;   //�Ƿ񱻱��� ״̬

};
