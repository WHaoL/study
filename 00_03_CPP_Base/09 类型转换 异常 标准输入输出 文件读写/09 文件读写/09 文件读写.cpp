#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <fstream>
#include <string>


void test01()
{
	//д�ļ�
	//ofstream ofs("./test.txt", ios::out | ios::trunc); //���ô򿪷�ʽ ����λ��������ö����ʽ

	ofstream ofs;
	ofs.open("./test.txt", ios::out | ios::trunc);

	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	ofs << "������Tom" << endl;
	ofs << "���䣺18" << endl;
	ofs << "�Ա���" << endl;

	//�رն���
	ofs.close();
}

void test02()
{
	//���ļ�

	ifstream ifs;
	ifs.open("./test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}

	//��һ�ֶ�ȡ��ʽ
	//char buf[1024] = { 0 };

	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}


	//�ڶ��ַ�ʽ
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
	//�����ַ�ʽ
	//string buf;
	//while (getline(ifs,buf))
	//{
	//	cout << buf << endl;
	//}

	//�����ַ�ʽ ���ַ���
	char c;
	while ( (c = ifs.get()) !=EOF)
	{
		cout << c;
	}

	//�ر��ļ�
	ifs.close();

}

int main(){

	//test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}