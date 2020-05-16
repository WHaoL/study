#include "config.h"


//获取文件行数
int getFileLines(char * fileName)
{
	FILE * fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		perror("fopen err");
		return -1;
	}

	char buf[1024] = { 0 };
	int lines = 0;
	while (fgets(buf,1024,fp) != NULL)
	{
		if ( isValidLine(buf)) //如果验证的是有效信息，统计有效行数
		{
			lines++;
		}
	
		memset(buf, 0, 1024);
	}

	fclose(fp);
	return lines;
}

int isValidLine(char * buf)
{
	if (buf[0] == '\n' || buf[0] == ' ' ||  strchr(buf,':')== NULL )
	{
		return 0;
	}

	return 1;
}


//解析文件
void parseFile(char * fileName, int lines, struct ConfigInfo ** configInfo)
{
	//分配内存
	struct ConfigInfo * temp = malloc(sizeof(struct ConfigInfo) * lines);

	//读文件
	FILE * fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		perror("fopen err");
		return;
	}

	char buf[1024] = { 0 };
	int index = 0;
	while (fgets(buf, 1024, fp) != NULL)
	{
		//如果是有效信息 才去解析
		if (isValidLine(buf))
		{
			//heroId:111\n
			//先将key清空
			memset(temp[index].key, 0, 64);
			//再清空value
			memset(temp[index].value, 0, 64);

			char * pos = strchr(buf, ':'); //:的位置
			strncpy(temp[index].key, buf, pos - buf);

			strncpy(temp[index].value, pos + 1, strlen(pos + 1)-1); // 最后-1的目的是不要文件中的换行

			//printf("key = %s\n", temp[index].key);
			//printf("value = %s\n", temp[index].value);
			index++;
		}
	}

	//建立关系
	*configInfo = temp;
}


//根据key获取value
char * getValueByKey(char * key, struct ConfigInfo * configInfo, int len)
{
	for (int i = 0; i < len;i++)
	{
		//if (configInfo[i].key == key)
		if ( strcmp(configInfo[i].key,key ) == 0)
		{
			return configInfo[i].value;
		}
	}
	return NULL;
}

//释放堆区
void freeSpace(struct ConfigInfo * configInfo)
{
	if (configInfo != NULL)
	{
		free(configInfo);
		configInfo = NULL;
	}
	
}