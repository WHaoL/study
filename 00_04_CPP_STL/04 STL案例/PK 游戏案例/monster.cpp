#include "monster.h"
#include "fileManager.h"
#include <string>

Monster::Monster(int monsterId)
{
	FileManager fm;
	map<string, map<string, string>>mMonsterData;
	fm.loadCSVData("Monsters.csv", mMonsterData);

	string tmpId = to_string(monsterId);
	//����Id��
	string id = mMonsterData[tmpId]["monsterId"];

	this->monsterName = mMonsterData[id]["monsterName"]; //��������

	this->monsterAtk = atoi(mMonsterData[id]["monsterAtk"].c_str()); //������

	this->monsterDef = atoi(mMonsterData[id]["monsterDef"].c_str()); //������

	this->monsterHp = atoi(mMonsterData[id]["monsterHp"].c_str()); //Ѫ��

	this->isFrozen = false;//����״̬
}

void Monster::Attack(Hero *hero)
{
	//���ж������Ƿ񱻱�������������޷�����
	if (this->isFrozen)
	{
		cout << "���� << " << this->monsterName << " >> �������ˣ����غ��޷�������" << endl;
		return;
	}

	//�����˺�
	int damage = (this->monsterAtk - hero->heroDef > 0) ? this->monsterAtk - hero->heroDef : 1;

	//Ӣ�۵�Ѫ
	hero->heroHp -= damage;

	cout << "����<< " << this->monsterName << " >> ������Ӣ�� << " << hero->heroName << " >> ��ɵ��˺�Ϊ��" << damage << endl;
}
