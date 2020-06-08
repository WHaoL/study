#pragma  once 
#include <iostream>
using namespace std;
#include <vector>
#include <map>

//文件管理类
class FileManager
{
public:

	//读取csv文件信息
	void loadCSVData(string fileName, map<string,map<string,string>>&m );

	//解析单行数据 放入到指定的容器中
	void parseLineToVector(string line, vector<string>&v);

};