#ifndef __SERVER_GLOBAL_H__
#define __SERVER_GLOBAL_H__
#include <iostream>
#include <string>

typedef struct {
    std::string ItemName;
    std::string ItemContent;
}CConfItem, *PTRConfItem;

extern char ** g_os_argv;
extern int g_environlen;
extern char *gp_envmem;
#endif