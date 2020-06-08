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

	this->heroName = mHeroData[id]["heroName"]; //Ӣ������

	this->heroAtk =  atoi(mHeroData[id]["heroAtk"].c_str()); //Ӣ�۹�����

	this->heroDef = atoi(mHeroData[id]["heroDef"].c_str()); //Ӣ�۷�����

	this->heroHp = atoi(mHeroData[id]["heroHp"].c_str()); //Ӣ��Ѫ��

	this->heroInfo = mHeroData[id]["heroInfo"]; //Ӣ�ۼ��

	this->weapon = NULL; //����ָ�� ��ʼ��ΪNULL

}

void Hero::Attack(Monster * monster)
{
	int crit = 0;
	int suck = 0; 
	int frozen = 0;
	int damage = 0;

	if (this->weapon == NULL) //û��װ��������û����Ч
	{
		damage = this->heroAtk;
	}
	else
	{
		//�˺�
		damage = this->heroAtk + weapon->getBaseDamage();

		//����
		crit = this->weapon->getCrit();

		//��Ѫ
		suck = this->weapon->getSuckBlood();

		//����
		frozen = this->weapon->getFrozen();
	}

	if (crit) //��������
	{
		damage += crit;
		cout << "Ӣ�۵����������˱���Ч�� ,�����ܵ������˺���" << endl;
	}

	if (suck) //������Ѫ
	{
		cout << "Ӣ�۵�������������ѪЧ����Ӣ������Ѫ����" << suck << endl;
	}

	if (frozen)
	{
		cout << "Ӣ�۵����������˱���Ч��������<< " << monster->monsterName << " >> ֹͣ����һ�غ�" << endl;
	}
	monster->isFrozen = frozen; //���¹������״̬
	this->heroHp += suck; //���»�Ѫ��ֵ
	int trueDamage = (damage - monster->monsterDef) > 0 ? (damage - monster->monsterDef) : 1;
	monster->monsterHp -= trueDamage;

	cout << "Ӣ�� << " << this->heroName << " >> �����˹��� << " << monster->monsterName << " >> ��ɵ��˺�Ϊ�� " << trueDamage << endl;
}

void Hero::EquipWeapon(Weapon * weapon)
{
	if (weapon == NULL) //��װ������
	{
		return;
	}

	this->weapon = weapon;

	cout << "Ӣ�� << " << this->heroName << " >> װ�������� :" << weapon->weaponName << "!" << endl;
}
