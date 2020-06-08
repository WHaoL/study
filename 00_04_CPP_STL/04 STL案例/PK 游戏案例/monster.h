#pragma once
#include <iostream>
using namespace std;
#include "hero.h"

class Hero;
class Monster
{
public:
	//有参构造 
	Monster(int monsterId);
	//怪物攻击函数实现
	void Attack(Hero *hero);
public:
	string monsterName; //怪物姓名
	int monsterHp;  //怪物血量
	int monsterAtk;  //怪物攻击力
	int monsterDef;  //怪物防御力
	bool isFrozen;   //是否被冰冻 状态

};
