#pragma once
#include <iostream>
using namespace std;

//所有武器的基类
class Weapon
{
public:

	//获取基础伤害
	virtual int getBaseDamage() = 0;
	//暴击效果 返回值大于0 触发暴击
	virtual int getCrit() = 0;
	//获取吸血 返回值大于0 触发吸血
	virtual int getSuckBlood() = 0;
	//冰冻效果 返回true 代表冰冻
	virtual int getFrozen() = 0;

	//触发概率
	virtual bool isTrigger(int rate) = 0;

	//基础攻击
	int baseDamage;
	//武器名称
	string weaponName;
	//武器暴击系数
	int critPlus;
	//暴击率
	int critRate;
	//吸血系数
	int suckPlus;
	//吸血率
	int suckRate;
	//冰冻率
	int forzenRate;

};