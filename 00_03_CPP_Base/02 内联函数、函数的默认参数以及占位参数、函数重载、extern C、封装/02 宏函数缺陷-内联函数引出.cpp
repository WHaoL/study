#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1����ȱ��1��������ʱ������ű�֤������
#define MYADD(x,y) ((x) +(y))
void test01()
{
	int a = 10;
	int b = 20;
	int ret = MYADD(a, b) * 20;
	cout << ret << endl;
}

//2����ȱ��2����ʹ�������ţ���Щ�����Ȼ��Ԥ��Ч������
//ȡСֵ
#define MYCOMPARE(a,b)   (((a) < (b)) ? (a) : (b))

//��ͨ����
int myCompare(int a, int b)
{
	return a < b ? a : b;
}

void test02()
{
	int a = 10;
	int b = 20;

	//int ret = MYCOMPARE(++a, b); //Ԥ�ڷ��ؽ�� 11  (((++a) < (b)) ? (++a) : (b)) ʵ�����12

	int ret = myCompare(++a, b); //��ͨ������Ԥ��Ч������
	cout << "ret = " << ret << endl;
}

//��������
//���������ô�  ����ͨ����һ���������к�ȱ�ݣ������ʵ��ĵط������ƺ��滻���Կռ任ʱ��
//������������ʵ�ֱ���ͬʱ�� inline�ؼ��֣���������ų�Ϊ���������ĺ�ѡ��
inline void func(int a, int b);
inline void func(int a, int b)
{
}

//��Ա������ǰ�棬�����صļ���inline�ؼ���

int main(){

	test02();

	system("pause");
	return EXIT_SUCCESS;
}