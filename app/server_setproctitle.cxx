#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../_include/server_global.h"

void server_init_setproctitle()
{
    int i;
    for(i = 0; environ[i]; ++ i)
    {
        g_environlen += strlen(environ[i]) + 1;
    }
    gp_envmem = new char[g_environlen];
    memset(gp_envmem, 0, g_environlen);
    char *ptmp = gp_envmem;

    for(i = 0; environ[i]; ++ i)
    {
        size_t size = strlen(environ[i]) + 1;
        strcpy(ptmp, environ[i]);
        environ[i] = ptmp;
        ptmp += size;
    }

    return;
}

void server_setproctitle(const char *title)
{
    size_t len = strlen(title);
    size_t e_environlen = 0;
    for(int i = 0; g_os_argv[i]; i++)
    {
        e_environlen += strlen(g_os_argv[i]) + 1;
    }
    size_t esy = e_environlen + g_environlen;
    if(esy <= len)  return;

    g_os_argv[1] = NULL;
    char* ptmp = g_os_argv[0];
    strcpy(ptmp, title);
    ptmp += len;
    memset(ptmp, '\0', esy - len);

}