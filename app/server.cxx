#include <stdio.h>
#include <iostream>
#include <unistd.h>

#include "../_include/server_signal.h"
#include "../_include/server_func.h"
#include "../_include/server_c_conf.h"

//设置进程名有关的全局变量
char **g_os_argv;
char *gp_envmem = nullptr;
int g_environlen = 0;
void server_init_setproctitle();
void server_setproctitle(const char *);


int main(int argc, char **argv) 
{

    //设置进程名
    g_os_argv = reinterpret_cast<char **>(argv);
    server_init_setproctitle();
    server_setproctitle("chaos: master");

    printf("欢迎！\n");

    CConfig* p_config = CConfig::GetInstance();
    if(!p_config->Load("server.conf"))
    {
        printf("配置文件载入失败，退出\n");
        exit(1);
    }
    mysignal();
    std::cout << Trim("  #这行是注释    ！    ") << std::endl;
    printf("退出\n");
    if(gp_envmem != nullptr) 
    {
        delete[] gp_envmem;
        gp_envmem = nullptr;
    }

    return 0;
}