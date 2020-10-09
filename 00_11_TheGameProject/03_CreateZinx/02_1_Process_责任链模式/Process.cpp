#include "Process.h"
#include <algorithm>
using namespace std;

Process::Process(/* args */)
{
}

Process::~Process()
{
}

void Process::DataProc(std::string _input)
{
    if (_input[0] >= 'a' && _input[0] <= 'z') //参数中第一个字母是小写字母，则转大写输出
        UpperOut(_input);
    else //否则原样输出
        OriginalOut(_input);
}

void Process::UpperOut(std::string _input)
{
    transform(_input.begin(), _input.end(),
              _input.begin(),
              ::toupper);
    m_out_channel->Data_Sendout(_input);
}

void Process::OriginalOut(std::string _input)
{
    m_out_channel->Data_Sendout(_input);
}