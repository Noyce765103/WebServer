#include <stdio.h>
#include <unistd.h>

#include "server_func.h"
#include "server_signal.h"

int main(int argc, char **argv) 
{
    printf("欢迎！\n");
    myconf();
    mysignal();
    printf("退出\n");
    return 0;
}