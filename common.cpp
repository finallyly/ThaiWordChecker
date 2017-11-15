/*===============================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   文件名称：common.cpp
*   创 建 者：unicodeproject
*   创建日期：2016年07月20日
*   描    述：
*   备    注: 
*   更新日志：
*
================================================================*/
 
#include "common.h"
// please add your code here!
// split string like a;b;c;
void SplitString(std::string original, std::vector<std::string>&results, std::string strdim)
{
    char tempstr[TEXT_LEN1] = {0};
    char delims[TEXT_LEN1] = {0};
    strcpy(tempstr, original.c_str());
    strcpy(delims,strdim.c_str());
    char *p = NULL; 
    p = strtok(tempstr,delims);
    if (NULL != p)
    {
        if (0 != strcmp(p,"")) 
        {
            results.push_back(p);
        }
    }
    while ((p = strtok(NULL,delims))!=NULL)
    {
        if (0 != strcmp(p,""))
        {
            results.push_back(p);
        }
    }
}
