#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{

	extern const int g_b;
	cout << "g_b = " << g_b << endl;

	system("pause");
	return EXIT_SUCCESS;
}