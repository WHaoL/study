#include "fileManager.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

//加载Csv文件数据的函数
void FileManager::loadCSVData(string fileName, map<string, map<string, string>>&mData)
{
	//读文件
	ifstream ifs(fileName);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	string firstLine;
	ifs >> firstLine;

	//cout << "第一行数据为： " << firstLine << endl;

	//将第一行数据截取到容器中
	vector<string>vFirst;

	//将字符串解析后 放入到 容器中
	parseLineToVector(firstLine, vFirst);

	////解析第二行
	//string secondLine;
	//ifs >> secondLine;
	//vector<string>vSecond;
	//parseLineToVector(secondLine, vSecond);

	//最大map容器 ，存放所有数据
	//map<string, map<string, string>>mData;

	string otherLine;
	while (ifs >> otherLine)
	{
		vector<string>otherV;
		parseLineToVector(otherLine, otherV);

		//for_each(otherV.begin(), otherV.end(), [](string str){cout << str << " "; });
		//cout << endl;

		//将key 和 value 组装到一个map容器中
		map<string, string>m;
		for (int i = 0; i < otherV.size();i++)
		{
			m.insert(make_pair(vFirst[i], otherV[i]));
		}

		mData.insert(make_pair(otherV[0], m));
	}

	/*cout << "1号姓名： " << mData["1"]["heroName"] << endl;
	cout << "3号简介： " << mData["3"]["heroInfo"] << endl;*/

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
