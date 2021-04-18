#include "AnnotationConvert.h"

enum STATE state = NUL_STATE; //初识状态为：NUL 未知态

void Convert(FILE *fR, FILE *fW)
{
    while (state != END_STATE) //扫描到文件尾 跳出循环
    {
        switch (state)
        {
        case NUL_STATE:
            Do_NUL_State(fR, fW);
            break;
        case C_STATE:
            Do_C_State(fR, fW);
            break;
        case CPP_STATE:
            Do_Cpp_State(fR, fW);
            break;
        default:
            break;
        }
    }
}

void Do_NUL_State(FILE *fR, FILE *fW)
{
    int first = 0;
    int second = 0;
    first = fgetc(fR); //fgetc返回字符对应的unsigneint
    switch (first)
    {
    case '/':
        second = fgetc(fR);
        if (second == '*') // 遇到/* 转为C状态
        {
            fputc('/', fW);
            fputc('/', fW);
            state = C_STATE;
        }
        else if (second == '/') // 遇到 // 转为C++状态
        {
            fputc(first, fW);  // '/'
            fputc(second, fW); // '/'
            state = CPP_STATE;
        }
        else //表示 first只是一个简单的'/'字符，输出即可
        {
            fputc(first, fW);
            fputc(second, fW);
        }
        break;

    case EOF: //文件尾
        // fputc(EOF, fW);
        state = END_STATE;
        break;
    default: //状态不变，正常输出
        fputc(first, fW);
        break;
    }
}
void Do_C_State(FILE *fR, FILE *fW) //C状态
{
    int first = 0;
    int second = 0;
    int third = 0;
    first = fgetc(fR);
    switch (first)
    {
    case '*':
        second = fgetc(fR);
        switch (second)
        {
        case '/':
            third = fgetc(fR);
            if (third != '\n') // *等到了/  一次C注释结束了，期待一个换行符'\n'
            {
                fputc('\n', fW);   //若是没有遇到换行符，帮它换行
                ungetc(third, fR); //并将字符放回去，用于下一次的判断
                state = NUL_STATE;
            }
            else
            {
                fputc(third, fW); //若是遇到了换行符，换行即可
                state = NUL_STATE;
            }
            break;
        case '*':
            //second=='*'在等'/'的到来,所以first已经没用了 舍弃first=='*' ,所以不输出first=='*'
            //把second放回去，是因为second=='*'在C状态下，下一个字符可能是'/' ,这样就扫描到来注释尾
            //把second=='*'放回去，是为了检测下一个字符是否是'/'
            ungetc(second, fR);
            break;
        default:
            //'*'没有等到'/' ; 那么舍弃这个first=='*' , 并输出这个second( !='*'  !='/' )(是个普通字符)
            ungetc(second, fR);
            break;
        }
        break;
    case '\n':
        fputc(first, fW); // '\n'
        fputc('/', fW);   //
        fputc('/', fW);   //
        break;
    case EOF:
        // fputc(EOF, fW);
        state = END_STATE;
        break;
    default:
        fputc(first, fW);
        break;
    }
}
void Do_Cpp_State(FILE *fR, FILE *fW)
{
    int first = 0;
    first = fgetc(fR);
    switch (first)
    {
    case '\n':
        fputc(first, fW);
        state = NUL_STATE;
        break;
    case EOF:
        // fputc(EOF, fW);
        state = END_STATE;
        break;
    default:
        fputc(first, fW);
        break;
    }
}
