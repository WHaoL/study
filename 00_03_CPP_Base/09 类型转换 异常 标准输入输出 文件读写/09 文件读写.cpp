//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <fstream>
#include <string>

// out ���ѳ����е����ݣ�д�뵽�����ļ�
// in  �����ļ��е����ݣ���ȡ������

//------------------------------�ѳ����е�����д�뵽����--------------------------------//
void test01()
{
	//���ô򿪷�ʽ ����λ��������ö����ʽ
	// ios::out д���ݵ��ļ�
	// ios::trunc �򿪲����һ���ļ������ߡ�����һ���ļ�

	ofstream ofs;

	ofs.open("./testSourceFile.txt", ios::out | ios::trunc);

	// bool std::ofstream::is_open()
	// ˵����
	// 		����ļ����Ƿ��й����ļ���
	// ����ֵ
	// 		���ļ����й����ļ�����Ϊ true ��(֤���ɹ������ļ�)
	//      ����Ϊ false �� (֤����ǰ����û�гɹ����ļ�)
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

//------------------------------�Ӵ��̶����ݵ�������--------------------------------//

void test021()
{
	ifstream ifs;
	ifs.open("./testSourceFile.txt", ios::in);

	ofstream ofs;
	ofs.open("./testTargetFile021.txt", ios::out | ios::trunc);

	if ((!ifs.is_open()) || (!ofs.is_open()))
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//��һ�ֶ�ȡд�뷽ʽ
	// ifs.eof()
	//		����trueʱ��֤��ָ�����ļ�β(�ļ���ȡ���)
	//      ����falseʱ��֤��ָ��û���ļ�β(�ļ�û�ж�ȡ���)
	while (!ifs.eof())
	{
		char buf[1024] = {0};
		ifs.getline(buf, 1024); //����
		//ofs << buf ;		//д��
		ofs << buf << endl; //д�루���һ�л��д��һ���س���
	}

	//�ر��ļ�������
	ifs.close();
	ofs.close();
}
//------------------------------�Ӵ��̶����ݵ�������--------------------------------//
void test022()
{
	ifstream ifs;
	ifs.open("./testSourceFile.txt", ios::in);

	ofstream ofs;
	ofs.open("./testTargetFile022.txt", ios::out | ios::trunc);

	if ((!ifs.is_open()) || (!ofs.is_open()))
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//�ڶ��ֶ�ȡд�뷽ʽ ���ַ���ȡд��
	char c;
	while ((c = ifs.get()) != EOF)
	{
		ofs << c; //���һ�в����д��һ���س���������
	}

	//�ر��ļ�������
	ifs.close();
	ofs.close();
}
//------------------------------�Ӵ��̶����ݵ�������--------------------------------//
// ����
void test02()
{
	ifstream ifs;
	ifs.open("./testSourceFile.txt", ios::in);

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
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	//�ر��ļ�������
	ifs.close();
}

int main()
{

	test01();

	test021();
	test022();

	//system("pause");
	return EXIT_SUCCESS;
}