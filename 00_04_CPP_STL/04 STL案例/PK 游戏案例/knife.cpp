#include "knife.h"
#include "fileManager.h"

Knife::Knife()
{
	//�����Գ�ʼ��

	//��ȡ�����˺�
	FileManager fm;
	map<string, map<string, string>>mWeaponData;
	fm.loadCSVData("Weapons.csv", mWeaponData);

	string id = mWeaponData["1"]["weaponId"];

	this->weaponName = mWeaponData[id]["weaponName"]; //��������
	// string ->  char *    -> int 
	//   .c_str()         atoi()
	this->baseDamage = atoi( mWeaponData[id]["weaponAtk"].c_str()); //�����˺�
	this->critPlus = atoi(mWeaponData[id]["weaponCritPlus"].c_str()); //��������ϵ��
	this->critRate = atoi(mWeaponData[id]["weaponCritRate"].c_str()); //����������
	this->suckPlus = atoi(mWeaponData[id]["weaponSuckPlus"].c_str()); //������Ѫϵ��
	this->suckRate = atoi(mWeaponData[id]["weaponSuckRate"].c_str()); //������Ѫ��
	this->forzenRate = atoi(mWeaponData[id]["weaponFrozenRate"].c_str()); //����������

}

int Knife::getBaseDamage()
{
	return this->baseDamage;
}

//��ȡ����
int Knife::getCrit()
{
	//��������������������������˺�* ����ϵ��
	if ( isTrigger(this->critRate) )
	{
		return this->baseDamage * this->critPlus;
	}
	else
	{
		return 0;
	}
}

//��ȡ��Ѫ
int Knife::getSuckBlood()
{
	//���������Ѫ���������������˺�* ��Ѫϵ��
	if (isTrigger(this->suckRate))
	{
		return this->baseDamage * this->suckPlus;
	}
	else
	{
		return 0;
	}
}

//��ȡ����
int Knife::getFrozen()
{
	//���������Ѫ���������������˺�* ��Ѫϵ��
	if (isTrigger(this->forzenRate))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//�Ƿ񴥷����ʺ���
bool Knife::isTrigger(int rate)
{
	int num = rand() % 100 + 1;    //1~100;
	if (num <= rate)
	{
		return true;
	}
	return false;
}
