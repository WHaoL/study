#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1��using ����
namespace KingGlory
{
	int sunwukongId = 1;
}
void test01()
{
	int sunwukongId = 2;

	//��using�����;ͽ�ԭ��ͬʱ���֣�������������ԣ���������
	// ���߱���������ʹ�õ��� KingGlory�������µ� sunwukongId
	//using KingGlory::sunwukongId;
	cout << "sunwukongId = " << sunwukongId << endl;
}

//2��using����ָ�� 

namespace LOL
{
	int sunwukongId = 3;
}

void test02()
{

	//int sunwukongId = 2;

	//����ָ��
	//���ͽ�ԭ����usingָ��ͬʱ���֣�����ʹ���Ǿͽ�ԭ��
	using namespace KingGlory;
	using namespace LOL;
	//��using������ͬ��������֣���Ҫ������������

	cout << "sunwukongId = " << LOL::sunwukongId << endl;
}

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}