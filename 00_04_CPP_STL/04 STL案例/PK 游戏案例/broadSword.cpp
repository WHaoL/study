#include "broadSword.h"
#include "fileManager.h"

BroadSword::BroadSword()
{
	//给属性初始化

	//获取基础伤害
	FileManager fm;
	map<string, map<string, string>>mWeaponData;
	fm.loadCSVData("Weapons.csv", mWeaponData);

	string id = mWeaponData["2"]["weaponId"];

	this->weaponName = mWeaponData[id]["weaponName"]; //武器名称
	// string ->  char *    -> int 
	//   .c_str()         atoi()
	this->baseDamage = atoi(mWeaponData[id]["weaponAtk"].c_str()); //武器伤害
	this->critPlus = atoi(mWeaponData[id]["weaponCritPlus"].c_str()); //武器暴击系数
	this->critRate = atoi(mWeaponData[id]["weaponCritRate"].c_str()); //武器暴击率
	this->suckPlus = atoi(mWeaponData[id]["weaponSuckPlus"].c_str()); //武器吸血系数
	this->suckRate = atoi(mWeaponData[id]["weaponSuckRate"].c_str()); //武器吸血率
	this->forzenRate = atoi(mWeaponData[id]["weaponFrozenRate"].c_str()); //武器冰冻率

}

int BroadSword::getBaseDamage()
{
	return this->baseDamage;
}

//获取暴击
int BroadSword::getCrit()
{
	//如果触发暴击，返回武器基础伤害* 暴击系数
	if (isTrigger(this->critRate))
	{
		return this->baseDamage * this->critPlus;
	}
	else
	{
		return 0;
	}
}

//获取吸血
int BroadSword::getSuckBlood()
{
	//如果触发吸血，返回武器基础伤害* 吸血系数
	if (isTrigger(this->suckRate))
	{
		return this->baseDamage * this->suckPlus;
	}
	else
	{
		return 0;
	}
}

//获取冰冻
int BroadSword::getFrozen()
{
	//如果触发吸血，返回武器基础伤害* 吸血系数
	if (isTrigger(this->forzenRate))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//是否触发概率函数
bool BroadSword::isTrigger(int rate)
{
	int num = rand() % 100 + 1;    //1~100;
	if (num <= rate)
	{
		return true;
	}
	return false;
}
