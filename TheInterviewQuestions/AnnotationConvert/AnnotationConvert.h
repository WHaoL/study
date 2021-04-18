#ifndef __ANNOTATION_CONVERT_H__
#define __ANNOTATION_CONVERT_H__
#include <stdio.h>
#include <stdlib.h>

// C语言风格的注释   /**/
// C++语言风格的注释 //
// 本程序的目标：将C语言风格的注释转换为C++风格的注释
// 待测试数据存在test_in.c文件中 输出结果到test_out.c文件中
#define InputFileName "test_in"
#define OutputFileName "test_out"

enum STATE
{
    NUL_STATE, // 空状态
    C_STATE,   // C语言注释状态
    CPP_STATE, // C++语言注释状态
    END_STATE  // 结束状态
};

void Convert(FILE *fR, FILE *fW);
void Do_NUL_State(FILE *fR, FILE *fW);
void Do_C_State(FILE *fR, FILE *fW);
void Do_Cpp_State(FILE *fR, FILE *fW);

#endif
