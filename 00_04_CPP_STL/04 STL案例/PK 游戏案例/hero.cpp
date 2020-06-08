#include "hero.h"
#include "fileManager.h"
#include <string>

Hero::Hero(int heroId)
{
	FileManager fm;
	map<string, map<string, string>>mHeroData;
	fm.loadCSVData("hero.csv", mHeroData);

	//int -> string 
	string tmpId = to_string(heroId);
	string id = mHeroData[tmpId]["heroId"];

	this->heroName = mHeroData[id]["heroName"]; //英雄姓名

	this->heroAtk =  atoi(mHeroData[id]["heroAtk"].c_str()); //英雄攻击力

	this->heroDef = atoi(mHeroData[id]["heroDef"].c_str()); //英雄防御力

	this->heroHp = atoi(mHeroData[id]["heroHp"].c_str()); //英雄血量

	this->heroInfo = mHeroData[id]["heroInfo"]; //英雄简介

	this->weapon = NULL; //武器指针 初始化为NULL

}

void Hero::Attack(Monster * monster)
{
	int crit = 0;
	int suck = 0; 
	int frozen = 0;
	int damage = 0;

	if (this->weapon == NULL) //没有装备武器，没有特效
	{
		damage = this->heroAtk;
	}
	else
	{
		//伤害
		damage = this->heroAtk + weapon->getBaseDamage();

		//暴击
		crit = this->weapon->getCrit();

		//吸血
		suck = this->weapon->getSuckBlood();

		//冰冻
		frozen = this->weapon->getFrozen();
	}

	if (crit) //触发暴击
	{
		damage += crit;
		cout << "英雄的武器触发了暴击效果 ,怪物受到暴击伤害！" << endl;
	}

	if (suck) //触发吸血
	{
		cout << "英雄的武器触发了吸血效果，英雄增加血量：" << suck << endl;
	}

	if (frozen)
	{
		cout << "英雄的武器触发了冰冻效果，怪物<< " << monster->monsterName << " >> 停止攻击一回合" << endl;
	}
	monster->isFrozen = frozen; //更新怪物冰冻状态
	this->heroHp += suck; //更新回血数值
	int trueDamage = (damage - monster->monsterDef) > 0 ? (damage - monster->monsterDef) : 1;
	monster->monsterHp -= trueDamage;

	cout << "英雄 << " << this->heroName << " >> 攻击了怪物 << " << monster->monsterName << " >> 造成的伤害为： " << trueDamage << endl;
}

void Hero::EquipWeapon(Weapon * weapon)
{
	if (weapon == NULL) //不装备武器
	{
		return;
	}

	this->weapon = weapon;

	cout << "英雄 << " << this->heroName << " >> 装备了武器 :" << weapon->weaponName << "!" << endl;
}
