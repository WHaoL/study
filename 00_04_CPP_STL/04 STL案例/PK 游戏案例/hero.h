#pragma once
#include <iostream>
using namespace std;
#include "weapon.h"
#include "monster.h"

class Monster;
//英雄类
class Hero
{
public:
//行为
	//英雄的有参构造
	Hero(int heroId);

	//英雄的攻击
	void Attack(Monster * monster);

	//装备武器
	void EquipWeapon(Weapon * weapon);

//属性
	//血量
	int heroHp;
	//攻击力
	int heroAtk;
	//防御力
	int heroDef;
	//姓名
	string heroName;
	//简介
	string heroInfo;
	//武器指针
	Weapon * weapon;
};