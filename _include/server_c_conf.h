#ifndef __SERVER_C_CONF_H__
#define __SERVER_C_CONF_H__
#include <string>
#include <vector>
#include "../_include/server_global.h"

class CConfig
{
private:
    CConfig();
public:
    ~CConfig();
private:
    static CConfig* m_instance;
public:
    static CConfig* GetInstance()
    {
        if(m_instance == nullptr)
        {
            //锁
            if(m_instance == nullptr)
            {
                m_instance = new CConfig();
                static CGarbageConfig c1;
            }
        }
        return m_instance;
    }
    class CGarbageConfig
    {
    public:
        ~CGarbageConfig()
        {
            if(CConfig::m_instance != nullptr)
            {
                delete CConfig::m_instance;
                CConfig::m_instance = nullptr;
            }
        }
    };

public:
    bool Load(const char* pconfName);
    std::string GetConfigContentByName(const char* ItemName) const;
    int GetIntDefault(std::string p_itemname, const int def);

private:
    std::vector<PTRConfItem> m_ConfigItemList;

public:
    void addConfigItem(const PTRConfItem& item) {
        m_ConfigItemList.push_back(item);
    }

};

#endif
