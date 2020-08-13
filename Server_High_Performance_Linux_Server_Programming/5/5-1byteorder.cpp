#include <stdio.h>
void byteorder()
{
    union 
    {
        short value;
        char union_bytes[sizeof(short)]; // [0] 低地址  [1] 高地址
    } test;

    test.value = 0x0102;                 // 01高位字节 02低位字节
    
    if ((test.union_bytes[0] == 2) && (test.union_bytes[1] == 1))
    {
        printf("little endian\n");
    }
    else if ((test.union_bytes[0] == 1) && (test.union_bytes[1] == 2))
    {
        printf("big endian\n");
    }
    else
    {
        printf("unknow...\n");
    }
}
int main()
{
    byteorder();
    getchar();
    return 0;
}