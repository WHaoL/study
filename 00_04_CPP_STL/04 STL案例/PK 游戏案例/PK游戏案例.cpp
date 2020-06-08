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

	cout << "��ӭ�������µ�һ�����" << endl;
	cout << "��ѡ������Ӣ�ۣ�" << endl;

	char buf[1024];
	sprintf(buf, "1��%s<%s>", mHeroData["1"]["heroName"].c_str(), mHeroData["1"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf(buf, "2��%s<%s>", mHeroData["2"]["heroName"].c_str(), mHeroData["2"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf(buf, "3��%s<%s>", mHeroData["3"]["heroName"].c_str(), mHeroData["3"]["heroInfo"].c_str());
	cout << buf << endl;

	int select = 0;
	cin >> select;
	getchar(); //�ѻ������еĻ���ȡ��

	Hero hero(select); //ʵ����Ӣ��
	cout << "��ѡ���Ӣ���ǣ� " << hero.heroName << endl;

	cout << "�������Ӣ��ѡһ��װ���� " << endl;


	map<string, map<string, string>>mWeaponData;
	fm.loadCSVData("Weapons.csv", mWeaponData);

	cout << "1�����ֿ�ȭ" << endl;

	sprintf(buf, "2��%s", mWeaponData["1"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "3��%s", mWeaponData["2"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "4��%s", mWeaponData["3"]["weaponName"].c_str());
	cout << buf << endl;

	cin >> select;
	getchar();

	Weapon * weapon = NULL;

	switch (select)
	{
	case 1:
		cout << "����ţX��������" << endl;
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

	//װ������
	hero.EquipWeapon(weapon);

	//��������
	int monsterId = 5; //rand() % 5 + 1; // 1 ~ 5
	Monster monster(monsterId);
	int round = 1;
	while (true)
	{
		getchar();
		system("cls"); //����

		cout << "��ǰ�ǵ� " << round << " �غ�" << endl;

		//�ж�Ӣ���Ƿ��Ѿ�����
		if (hero.heroHp <= 0)
		{
			cout << "Ӣ�ۣ�" << hero.heroName << "�ѹң���Ϸ������" << endl;
			break;
		}

		//Ӣ���ȹ���
		hero.Attack(&monster);

		//�жϹ���Ѫ��
		if (monster.monsterHp <= 0 )
		{
			cout << "��� " << monster.monsterName << "�ѹң���ϲ˳������!" << endl;
			break;
		}

		monster.Attack(&hero);

		cout << "Ӣ��ʣ��Ѫ��Ϊ��" << hero.heroHp << endl;
		cout << "����ʣ��Ѫ��Ϊ��" << monster.monsterHp << endl;

		//�ж�Ӣ���Ƿ��Ѿ�����
		if (hero.heroHp <= 0)
		{
			cout << "Ӣ�ۣ�" << hero.heroName << "�ѹң���Ϸ������" << endl;
			break;
		}

		round++;
	}


}

int main(){

	srand((unsigned int)time(NULL));

	FileManager fm;

	////��ȡӢ������
	//map<string, map<string, string>>mapHeroData;
	//fm.loadCSVData("hero.csv", mapHeroData);

	//cout << "1�������� " << mapHeroData["1"]["heroName"] << endl;
	//cout << "3�ż�飺 " << mapHeroData["3"]["heroInfo"] << endl;

	////��ȡ��������
	//map<string, map<string, string>>mapMonsterData;
	//fm.loadCSVData("Monsters.csv", mapMonsterData);

	//cout << "4�Ź������֣� " << mapMonsterData["4"]["monsterName"] << endl;
	//cout << "5�Ź������֣� " << mapMonsterData["5"]["monsterName"] << endl;

	////��ȡ��������
	//map<string, map<string, string>>mapWeaponData;
	//fm.loadCSVData("Weapons.csv", mapWeaponData);

	//cout << "1���������֣� " << mapWeaponData["1"]["weaponName"] << endl;
	//cout << "2���������֣� " << mapWeaponData["2"]["weaponName"] << endl;
	//cout << "3���������֣� " << mapWeaponData["3"]["weaponName"] << endl;


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