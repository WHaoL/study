#include "config.h"


//��ȡ�ļ�����
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
		if ( isValidLine(buf)) //�����֤������Ч��Ϣ��ͳ����Ч����
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


//�����ļ�
void parseFile(char * fileName, int lines, struct ConfigInfo ** configInfo)
{
	//�����ڴ�
	struct ConfigInfo * temp = malloc(sizeof(struct ConfigInfo) * lines);

	//���ļ�
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
		//�������Ч��Ϣ ��ȥ����
		if (isValidLine(buf))
		{
			//heroId:111\n
			//�Ƚ�key���
			memset(temp[index].key, 0, 64);
			//�����value
			memset(temp[index].value, 0, 64);

			char * pos = strchr(buf, ':'); //:��λ��
			strncpy(temp[index].key, buf, pos - buf);

			strncpy(temp[index].value, pos + 1, strlen(pos + 1)-1); // ���-1��Ŀ���ǲ�Ҫ�ļ��еĻ���

			//printf("key = %s\n", temp[index].key);
			//printf("value = %s\n", temp[index].value);
			index++;
		}
	}

	//������ϵ
	*configInfo = temp;
}


//����key��ȡvalue
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

//�ͷŶ���
void freeSpace(struct ConfigInfo * configInfo)
{
	if (configInfo != NULL)
	{
		free(configInfo);
		configInfo = NULL;
	}
	
}