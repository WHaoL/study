#pragma  once 
#include <iostream>
using namespace std;
#include <vector>
#include <map>

//�ļ�������
class FileManager
{
public:

	//��ȡcsv�ļ���Ϣ
	void loadCSVData(string fileName, map<string,map<string,string>>&m );

	//������������ ���뵽ָ����������
	void parseLineToVector(string line, vector<string>&v);

};