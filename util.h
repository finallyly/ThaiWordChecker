/*===============================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   文件名称：util.h
*   创 建 者：刘禹 finallyly liuyusi0121@sogou-inc.com(6141)
*   创建日期：2016年04月19日
*   描    述：utf-8转unicode,unicode转utf-8
*   备    注: 
*   更新日志：
*
================================================================*/
#ifndef _UTIL_H
#define _UTIL_H
#include <stdio.h>
#include <stdlib.h>
typedef int unicode_t;
typedef unsigned char uchar_t;
 //将一个unicode转成utf8编码
size_t enc_unicode_to_utf8_one(const unicode_t unic, char *pOutput, size_t outSize);
/*change unicode array to utf8 array, calculate the outputbuffer size, note the outputbuffersize dos not take '\0' in to consideration
when failed return 0
*/
size_t enc_calc_utf8_outsize(const unicode_t* unicArray,const size_t unicArraySize);
//change utf8 array to unicode, calc the outputbuffersize
size_t enc_calc_unicode_outsize(const char *pInput, const size_t inputLen);
//将unicode序列转成utf8编码序列；
size_t  enc_unicode_to_utf8_batch(const unicode_t* unicArray, const size_t unicArraySize, char *pOutput, int outSize);
//将一个utf8编码转换成unicode
size_t  enc_utf8_to_unicode_one(const char* pInput,unicode_t* Unic);
//将一个utf8编码序列转换成unicode序列
size_t enc_utf8_to_unicode_batch(const char* pInput, const size_t inputLen, unicode_t* UnicSeq, size_t outSize);
//根据开始字节判定该utf8串一共占几个字节
size_t enc_get_utf8_size(const char  c);
#endif
