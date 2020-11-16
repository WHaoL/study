#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

//6.1�����߳��˳�ʱ�Ĵ�������
struct Info
{
    char name[24];
    int age;
};

//7.2���߳����߳�֮�乲��ȫ����������������(ջ��������)
//�˴��������������Ϊȫ�ֱ���/�����������ǿ��Ե�
//struct Info info;

//1.2�����̵߳Ļص�����
//���̵߳Ĵ���
void *childFunc(void *arg)
{
    //8.2����ԭ��������
    struct Info *info = (struct Info *)arg;

    printf("child thread tid��%ld\n", pthread_self());
    for (int i = 0; i < 30; ++i)
    {
        printf("child_thread i = %d\n", i);
        //5������ĳЩ�������������̳߳��ִ���ʱ�������߳��˳�
        //�������߳�û��Ӱ��
        if (i == 10)
        {
            //6.2���ӽ����˳�ʱ�Ĵ�������

            //struct Info info;
            //7.1�����ܰ����ջ�������ݴ������߳�
            //��Ϊ���߳����߳�֮�䣬ջ��������
            //���߳��˳�����������ջ���ͱ��ͷ���

            strcpy(info->name, "lilei");
            info->age = 24;
            //pthread_exit(&info);//��������ȫ�ֱ����ĵ�ַ���ǿ��Ե�
            pthread_exit(info); //��������ȫ�ֱ����ĵ�ַ���ǿ��Ե�
            //˭�������̣߳�˭���ܽ��յ����̵߳Ĵ�������
        }
    } //ѭ��ִ����ϣ����߳̾��˳���
}

int main()
{
    //1.1�������߳�
    pthread_t ptid;

    //8.1�����̻߳������߳���Դʱ����Ϊ���̺߳���
    //���ԣ����̴߳��صĵ�ַ�����������߳�ջ���ĵ�ַ
    struct Info info; //�����̵߳�ջ�������������

    pthread_create(&ptid, NULL, childFunc, &info);

    //2����/���̵߳Ĵ���
    printf("��/���߳� �� tid��%ld\n", pthread_self());
    for (int i = 0; i < 5; ++i)
    {
        printf("i = %d\n", i);
    } //ѭ��ִ����ϣ����߳̾��˳���

    //3�������߳�˯һ�룬��ֹ�����ַ�ռ䱻����
    //sleep(1);
    //	���̺߳����̹߳��������ַ�ռ䣬���������߳�sleepһ��
    //	���������ַ�ռ�Ϳ��Զ�ά��һ�룬���������߳�ʹ��
    //	���߳�ִ����ϣ����߳��˳�
    //	���߳�˯����֮�����߳��˳������������ַ�ռ��û����

    //6���������߳���Դ
    //˭�������̣߳�˭���ܽ��յ����̵߳Ĵ�������
    struct Info *pt;
    pthread_join(ptid, (void **)&pt);
    printf("name��%s,age��%d\n", pt->name, pt->age);

    //4���˳����̣߳������߳�û��Ӱ��
    pthread_exit(NULL);
    return 0;
}
