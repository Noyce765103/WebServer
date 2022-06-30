#ifndef __SERVER_C_CONF_H__
#define __SERVER_C_CONF_H__
#include <string>
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
    bool Load(const std::string& pconfName);
    std::string GetString(std::string p_itemname);
    int GetIntDefault(std::string p_itemname, const int def);

};

#endif
