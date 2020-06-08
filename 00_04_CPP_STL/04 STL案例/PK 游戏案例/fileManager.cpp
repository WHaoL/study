#include "fileManager.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

//����Csv�ļ����ݵĺ���
void FileManager::loadCSVData(string fileName, map<string, map<string, string>>&mData)
{
	//���ļ�
	ifstream ifs(fileName);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	string firstLine;
	ifs >> firstLine;

	//cout << "��һ������Ϊ�� " << firstLine << endl;

	//����һ�����ݽ�ȡ��������
	vector<string>vFirst;

	//���ַ��������� ���뵽 ������
	parseLineToVector(firstLine, vFirst);

	////�����ڶ���
	//string secondLine;
	//ifs >> secondLine;
	//vector<string>vSecond;
	//parseLineToVector(secondLine, vSecond);

	//���map���� �������������
	//map<string, map<string, string>>mData;

	string otherLine;
	while (ifs >> otherLine)
	{
		vector<string>otherV;
		parseLineToVector(otherLine, otherV);

		//for_each(otherV.begin(), otherV.end(), [](string str){cout << str << " "; });
		//cout << endl;

		//��key �� value ��װ��һ��map������
		map<string, string>m;
		for (int i = 0; i < otherV.size();i++)
		{
			m.insert(make_pair(vFirst[i], otherV[i]));
		}

		mData.insert(make_pair(otherV[0], m));
	}

	/*cout << "1�������� " << mData["1"]["heroName"] << endl;
	cout << "3�ż�飺 " << mData["3"]["heroInfo"] << endl;*/

	ifs.close();
}

void FileManager::parseLineToVector(string firstLine, vector<string>&vFirst)
{

	int pos = -1;
	int start = 0;

	// heroId,heroName,heroHp,heroAtk,heroDef,heroInfo
	while (true)
	{
		pos = firstLine.find(",", start);
		if (pos == -1)
		{
			string tmpStr = firstLine.substr(start, firstLine.size() - start);
			vFirst.push_back(tmpStr);
			break;
		}
		string tmpStr = firstLine.substr(start, pos - start);
		vFirst.push_back(tmpStr);
		start = pos + 1;
	}

	//for (vector<string>::iterator it = vFirst.begin(); it != vFirst.end(); it++)
	//{
	//	cout << *it << endl;
	//}
}
