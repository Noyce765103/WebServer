#include <iostream>
#include "../_include/server_func.h"


// std::string Trim(std::string str)
// {
//     int n = str.size();
//     if(n == 0)  return str;
//     if(n == 1)  return str == " " ? "" : str;
//     int i = 0;
//     while(i < n && str[i] == ' ')   i ++;
//     str = str.substr(i);
//     n = str.size();
//     i = n - 1;
//     while(i >= 0 && str[i] == ' ') i --;
//     str = str.substr(0, i + 1);
//     return str;
// }

std::string Trim(const char* str)
{
    std::string s(str);
    int n = s.size();
    if(n == 0)  return s;
    if(n == 1)  return s == " " ? "" : s;
    int i = 0;
    while(i < n && s[i] == ' ')   i ++;
    s = s.substr(i);
    n = s.size();
    i = n - 1;
    while(i >= 0 && str[i] == ' ') i --;
    s = s.substr(0, i + 1);
    return s;
}

//原地修改
void Trim(std::string& str)
{
    int n = str.size();
    if(n == 0)  return ;
    if(n == 1)
    {
        if(str == " ")  str = "";
        else return;
    }
    else
    {
        int i = 0;
        while(i < n && str[i] == ' ')   i ++;
        str = str.substr(i);
        n = str.size();
        i = n - 1;
        while(i >= 0 && str[i] == ' ') i --;
        str = str.substr(0, i + 1);
    }
    return;
}