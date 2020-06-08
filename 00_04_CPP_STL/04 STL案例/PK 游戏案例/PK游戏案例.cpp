#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "fileManager.h"
#include <map>
#include <string>
#include "weapon.h"
#include "knife.h"
#include "broadSword.h"
#include "DragonSword.h"
#include "hero.h"
#include "monster.h"
#include <ctime>

void fight()
{
	FileManager fm;
	map<string, map<string, string>>mHeroData;
	fm.loadCSVData("hero.csv", mHeroData);

	cout << "欢迎来到天下第一武道会" << endl;
	cout << "请选择您的英雄：" << endl;

	char buf[1024];
	sprintf(buf, "1、%s<%s>", mHeroData["1"]["heroName"].c_str(), mHeroData["1"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf(buf, "2、%s<%s>", mHeroData["2"]["heroName"].c_str(), mHeroData["2"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf(buf, "3、%s<%s>", mHeroData["3"]["heroName"].c_str(), mHeroData["3"]["heroInfo"].c_str());
	cout << buf << endl;

	int select = 0;
	cin >> select;
	getchar(); //把缓冲区中的换行取走

	Hero hero(select); //实例化英雄
	cout << "您选择的英雄是： " << hero.heroName << endl;

	cout << "请给您的英雄选一件装备： " << endl;


	map<string, map<string, string>>mWeaponData;
	fm.loadCSVData("Weapons.csv", mWeaponData);

	cout << "1、赤手空拳" << endl;

	sprintf(buf, "2、%s", mWeaponData["1"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "3、%s", mWeaponData["2"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "4、%s", mWeaponData["3"]["weaponName"].c_str());
	cout << buf << endl;

	cin >> select;
	getchar();

	Weapon * weapon = NULL;

	switch (select)
	{
	case 1:
		cout << "你真牛X，等死吧" << endl;
		break;
	case 2:
		weapon = new Knife;
		break;
	case 3:
		weapon = new BroadSword;
		break;
	case 4:
		weapon = new DragonSword;
		break;
	default:
		break;
	}

	//装备武器
	hero.EquipWeapon(weapon);

	//创建怪物
	int monsterId = 5; //rand() % 5 + 1; // 1 ~ 5
	Monster monster(monsterId);
	int round = 1;
	while (true)
	{
		getchar();
		system("cls"); //清屏

		cout << "当前是第 " << round << " 回合" << endl;

		//判断英雄是否已经挂了
		if (hero.heroHp <= 0)
		{
			cout << "英雄：" << hero.heroName << "已挂，游戏结束！" << endl;
			break;
		}

		//英雄先攻击
		hero.Attack(&monster);

		//判断怪物血量
		if (monster.monsterHp <= 0 )
		{
			cout << "怪物： " << monster.monsterName << "已挂，恭喜顺利过关!" << endl;
			break;
		}

		monster.Attack(&hero);

		cout << "英雄剩余血量为：" << hero.heroHp << endl;
		cout << "怪物剩余血量为：" << monster.monsterHp << endl;

		//判断英雄是否已经挂了
		if (hero.heroHp <= 0)
		{
			cout << "英雄：" << hero.heroName << "已挂，游戏结束！" << endl;
			break;
		}

		round++;
	}


}

int main(){

	srand((unsigned int)time(NULL));

	FileManager fm;

	////获取英雄数据
	//map<string, map<string, string>>mapHeroData;
	//fm.loadCSVData("hero.csv", mapHeroData);

	//cout << "1号姓名： " << mapHeroData["1"]["heroName"] << endl;
	//cout << "3号简介： " << mapHeroData["3"]["heroInfo"] << endl;

	////获取怪物数据
	//map<string, map<string, string>>mapMonsterData;
	//fm.loadCSVData("Monsters.csv", mapMonsterData);

	//cout << "4号怪物名字： " << mapMonsterData["4"]["monsterName"] << endl;
	//cout << "5号怪物名字： " << mapMonsterData["5"]["monsterName"] << endl;

	////获取武器数据
	//map<string, map<string, string>>mapWeaponData;
	//fm.loadCSVData("Weapons.csv", mapWeaponData);

	//cout << "1号武器名字： " << mapWeaponData["1"]["weaponName"] << endl;
	//cout << "2号武器名字： " << mapWeaponData["2"]["weaponName"] << endl;
	//cout << "3号武器名字： " << mapWeaponData["3"]["weaponName"] << endl;


	//Weapon * weapon = new Knife;
	//cout << weapon->weaponName << endl;
	//cout << weapon->getBaseDamage() << endl;
	//delete weapon;

	//weapon = new BroadSword;
	//cout << weapon->weaponName << endl;
	//cout << weapon->getBaseDamage() << endl;
	//delete weapon;

	//weapon = new DragonSword;
	//cout << weapon->weaponName << endl;
	//cout << weapon->getBaseDamage() << endl;
	//delete weapon;

	fight();

	system("pause");
	return EXIT_SUCCESS;
}