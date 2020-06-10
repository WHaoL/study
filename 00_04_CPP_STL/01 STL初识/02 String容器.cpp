//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <vector>

/* 
3.1.2.1 string ���캯��
string();				   //����һ���յ��ַ��� ����: string str;
string(const string &str); //ʹ��һ��string�����ʼ����һ��string����
string(const char *s);	   //ʹ���ַ���s��ʼ��
string(int n, char c);	   //ʹ��n���ַ�c��ʼ��

3.1.2.2 string������ֵ����
string &operator=(const char *s);				   //char*�����ַ��� ��ֵ����ǰ���ַ���
string &operator=(const string &s);				   //���ַ���s������ǰ���ַ���
string &operator=(char c);						   //�ַ���ֵ����ǰ���ַ���
string &assign(const char *s);					   //���ַ���s������ǰ���ַ���
string &assign(const char *s, int n);			   //���ַ���s��ǰn���ַ�������ǰ���ַ���
string &assign(const string &s);				   //���ַ���s������ǰ�ַ���
string &assign(int n, char c);					   //��n���ַ�c������ǰ�ַ���
string &assign(const string &s, int start, int n); //��s��start��ʼn���ַ���ֵ���ַ��� 
*/

void test01()
{
	//����
	string str1;
	string str2 = str1;
	string str3 = "abcd";
	string str4(5, 'a');

	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	//��ֵ
	string str5;
	str5.assign("abcdefghi", 6);
	cout << "str5 = " << str5 << endl; //abcdef

	//string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���
	string str6;
	str6.assign(str5, 1, 4);		   //
	cout << "str6 = " << str6 << endl; //bcde
}

/*
3.1.2.3 string��ȡ�ַ�����
char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
char& at(int n);//ͨ��at������ȡ�ַ�
*/

void test02()
{
	string s = "hello world";

	//for (int i = 0; i < s.size();i++)
	//{
	//	//cout << s[i] << endl;
	//	//cout << s.at(i) << endl;
	//}

	//[]��at����[]����Խ�� ֱ�ӹҵ���at����Խ�磬�׳��쳣 out_of_range

	try
	{
		//cout << s[100] << endl;
		cout << s.at(100) << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}

/* 
3.1.2.4 stringƴ�Ӳ���
string &operator+=(const string &str);			 //����+=������
string &operator+=(const char *str);			 //����+=������
string &operator+=(const char c);				 //����+=������
string &append(const char *s);					 //���ַ���s���ӵ���ǰ�ַ�����β
string &append(const char *s, int n);			 //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string &append(const string &s);				 //ͬoperator+=()
string &append(const string &s, int pos, int n); //���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
string &append(int n, char c);					 //�ڵ�ǰ�ַ�����β���n���ַ�c 
*/

//ƴ��
void test03()
{
	string s1 = "��";
	s1 += "������";

	cout << s1 << endl;

	s1.append("�찲��");
	cout << s1 << endl;
}
/* 
//3.1.2.5 string���Һ��滻
int find(const string &str, int pos = 0) const;		//����str��һ�γ���λ��,��pos��ʼ����
int find(const char *s, int pos = 0) const;			//����s��һ�γ���λ��,��pos��ʼ����
int find(const char *s, int pos, int n) const;		//��posλ�ò���s��ǰn���ַ���һ��λ��
int find(const char c, int pos = 0) const;			//�����ַ�c��һ�γ���λ��
int rfind(const string &str, int pos = npos) const; //����str���һ��λ��,��pos��ʼ����
int rfind(const char *s, int pos = npos) const;		//����s���һ�γ���λ��,��pos��ʼ����
int rfind(const char *s, int pos, int n) const;		//��pos����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos = 0) const;			//�����ַ�c���һ�γ���λ��
string &replace(int pos, int n, const string &str); //�滻 ��pos��ʼ��n���ַ� Ϊ�ַ���str
string &replace(int pos, int n, const char *s);		//�滻 ��pos��ʼ��n���ַ� Ϊ�ַ���s
 */
//����
void test04()
{
	string str1 = "abcdefghde";

	int pos = str1.find("de"); //����2(Ĭ����0)��������ʼ����λ�ã�
	//find  �������Ҳ�
	//rfind ���������

	if (pos == -1)
	{
		cout << "δ�ҵ��Ӵ�" << endl;
	}
	else
	{
		cout << "�ҵ��Ӵ���λ�ã�" << pos << endl;
	}

	//�滻
	string str2 = "abcdefg";
	//string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
	str2.replace(1, 3, "11111");
	cout << str2 << endl; // a11111efg
}

/*
3.1.2.6 string�Ƚϲ���
compare���� 
	��>ʱ���� 1��<ʱ���� -1��==ʱ���� 0��
	�Ƚ����ִ�Сд���Ƚ�ʱ�ο��ֵ�˳����Խǰ���ԽС����д��A��Сд��aС��
int compare(const string &s) const;	//���ַ���s�Ƚ�
int compare(const char *s) const;	//���ַ���s�Ƚ�
*/

void test05()
{
	string str1 = "abcde";
	string str2 = "abcdefgh";

	int ret = str1.compare(str2);

	if (ret == 0)
	{
		cout << " str1 ==  str2 " << endl;
	}
	else if (ret == 1)
	{
		cout << " str1  >  str2 " << endl;
	}
	else
	{
		cout << " str1  <  str2 " << endl;
	}
}

/*
3.1.2.7 string�Ӵ�
string substr(int pos = 0, int n = npos) const;	//������pos��ʼ��n���ַ���ɵ��ַ���
*/
void test06()
{
	string str = "abcdefg";
	string subS = str.substr(0, 4); // abcd
	cout << subS << endl;

	string email = "zhangtao@sina.com";
	int pos = email.find("@");			   // pos = 8(��0��ʼ)
	string usrName = email.substr(0, pos); // 8
	cout << "name = " << usrName << endl;
}

//���
void test07()
{
	string str = "www.XTU.com.cn";
	vector<string> v;

	int pos = -1;
	int start = 0;

	while (true)
	{
		pos = str.find(".", start);
		if (pos == std::string::npos) //  std::string::nposһ�㶨��Ϊ-1
		{
			// ��ȡ���һ���ִ�
			string subS = str.substr(start, str.size() - start);
			v.push_back(subS);
			break;
		}
		// ��ȡǰ��ĸ����ִ�
		string subS = str.substr(start, pos - start); // pos = 10  start  = 4

		v.push_back(subS);

		start = pos + 1;
	}

	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}

/*
3.1.2.8 string�����ɾ������
string& insert(int pos, const char* s); 	//�����ַ���
string& insert(int pos, const string& str); //�����ַ���
string& insert(int pos, int n, char c);		//��ָ��λ�ò���n���ַ�c
string& erase(int pos, int n = npos);		//ɾ����Pos��ʼ��n���ַ�
*/
void test08()
{
	string str = "hello";
	//���룬����1 ָ��λ��  ����2 ��������
	str.insert(1, "2333");

	cout << str << endl; //h111ello

	//ɾ��
	str.erase(1, 3);
	cout << str << endl;
}

void doWork(const char *str)
{
}

void doWork2(string str)
{
}

//string��c-style�ַ���ת��
void test09()
{
	const char *str = "hello";

	//const char * תstring
	string str2 = string(str);

	//string ת  const char *
	const char *str3 = str2.c_str();

	//doWork(str2); //string ������ʽתΪ const char *
	doWork2(str3); //const char * ������ʽתΪ string
}

//�ַ������·����ڴ����ʹ��ԭ�������ÿ��ܻᷢ������
void test10()
{
	string s = "abcdefg";
	char &a = s[2];
	char &b = s[3];

	a = '1';
	b = '2';

	cout << s << endl;
	cout << (int *)s.c_str() << endl;

	s = "pppppppppppppppppppppppp";

	//a��b��������ʹ����
	//a = '1';
	//b = '2';

	cout << s << endl;
	cout << (int *)s.c_str() << endl;
}

/*
дһ�������������ڲ���string�ַ����е�����Сд��ĸ����Ϊ��д��ĸ��
*/
void test11()
{
	string str = "abCDefg";

	for (int i = 0; i < str.size(); i++)
	{
		//Сдת��д
		//str[i] = toupper(str[i]);

		//��дתСд
		str[i] = tolower(str[i]);
	}

	cout << str << endl;
}

int main()
{

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	test11();

	//system("pause");
	return 0;
}