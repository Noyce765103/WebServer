#include <cstddef>
#include <ios>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "../_include/server_func.h"
#include "../_include/server_c_conf.h"



void myconf()
{
    printf("执行了myconf函数,MYVER=%s!\n",MYVER);

}
CConfig* CConfig::m_instance = nullptr;

CConfig::CConfig()
{}

//装载配置文件函数
bool CConfig::Load(const std::string& pconfName)
{ 
    std::ifstream fin;
    fin.open(pconfName,std::ios_base::in);
    if(!fin.is_open())
    {
        //日志模块打印
        std::cout << "Error opening text file: " << pconfName <<std::endl;
        return false;
    }

}