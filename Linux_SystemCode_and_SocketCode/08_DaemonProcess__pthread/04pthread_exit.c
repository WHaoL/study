#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

//1.2�����̵߳Ļص�����
//���̵߳Ĵ���
void* childFunc(void* arg)
{
    printf("child thread tid��%ld\n",pthread_self());
    for(int i=0;i<30;++i)
    {
        printf("child i = %d\n",i);
        //5������ĳЩ�������������̳߳��ִ���ʱ�������߳��˳�
        //�������߳�û��Ӱ��
        if(i == 10)
        {
            pthread_exit(NULL);
        }
    }//ѭ��ִ����ϣ����߳̾��˳���
}

int main()
{
    //1.1�������߳�
    pthread_t ptid;
    pthread_create(&ptid,NULL,childFunc,NULL);
    //2����/���̵߳Ĵ���
    printf("��/���߳� �� tid��%ld\n",pthread_self());
    for(int i=0;i<5;++i)
    {
        printf("i = %d\n",i);
    }//ѭ��ִ����ϣ����߳̾��˳���
    
    //3�������߳�˯һ�룬��ֹ�����ַ�ռ䱻����
    //sleep(1);//���̺߳����̹߳��������ַ�ռ䣬���������߳�sleepһ��
             //���������ַ�ռ�Ϳ��Զ�ά��һ�룬���������߳�ʹ��
             //���߳�ִ����ϣ����߳��˳�
             //���߳�˯����֮�����߳��˳������������ַ�ռ��û����
    
    //4���˳����̣߳������߳�û��Ӱ��
    pthread_exit(NULL);
    return 0;
}


