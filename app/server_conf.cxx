#include <cstddef>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "../_include/server_func.h"
#include "../_include/server_c_conf.h"



CConfig* CConfig::m_instance = nullptr;

CConfig::CConfig()
{}

CConfig::~CConfig()
{
    for (auto item : m_ConfigItemList)
    {
        delete item;
    }
    m_ConfigItemList.clear();
}

//装载配置文件函数
bool CConfig::Load(const char* pconfName)
{ 
    std::ifstream fin;
    fin.open(pconfName,std::ios_base::in);
    if(!fin.is_open())
    {
        //日志模块打印
        std::cout << "Error opening text file: " << pconfName <<std::endl;
        return false;
    }
    else
    {
        std::string line;
        while(getline(fin, line))
        {
            //读入空行
            if(line == "")
                continue;
            Trim(line);
            if(line.size() <= 1)    continue;
            if(line[0] == '#' || line[0] == '\0' || line[0] == '\n' || line[0] == '\r' || line[0] == '[' || line[0] == ';' || line[0] == '\t') continue;
            auto idx = line.find('=');
            if(idx == -1) 
            {
                //日志记录错误
                std::cout << "日志文件配置错误，错误内容："<< line << std::endl;
                return false;
            }
            else 
            {
                PTRConfItem config = new CConfItem;
                config->ItemName = line.substr(0, idx);
                config->ItemContent = line.substr(idx + 1);
                Trim(config->ItemContent);
                Trim(config->ItemName);
                if(!m_instance) m_instance = CConfig::GetInstance();
                m_instance->addConfigItem(config);
            }
        }
    }
    fin.close();
    return true;

}

std::string CConfig::GetConfigContentByName(const char* name) const
{
    std::string res = "";
    for(const auto& config : m_ConfigItemList)
    {
        if(config->ItemName == name)
        {
            res = config->ItemContent;
            break;
        }
    }
    return res;
}