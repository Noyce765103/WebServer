#include <stdio.h>
#include <iostream>
#include <unistd.h>

#include "../_include/server_signal.h"
#include "../_include/server_func.h"
#include "../_include/server_c_conf.h"

int main(int argc, char **argv) 
{
    printf("欢迎！\n");

    CConfig* p_config = CConfig::GetInstance();
    if(!p_config->Load("server.conf"))
    {
        printf("配置文件载入失败，退出\n");
        exit(1);
    }
    std::cout <<p_config->GetConfigContentByName("DBServer") << std::endl;
    mysignal();
    std::cout << Trim("  #这行是注释    ！    ") << std::endl;
    printf("退出\n");
    return 0;
}