/*
 * @Date: 2023-10-24 15:13:25
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-10-24 15:33:01
 * @FilePath: \Assignment_2\Inc\CGramCheck.h
 */
#ifndef CGRAMCHECK_H
#define CGRAMCHECK_H

#include "CQueue.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CGramCheck
{
private:
    fstream file;

public:
    CGramCheck();
    ~CGramCheck();
    bool openCPP(const char *fileName);
    void checkGram(void);
};

inline CGramCheck::CGramCheck()
{
}

inline CGramCheck::~CGramCheck()
{
    // 关闭文件
    this->file.close();
}

#endif // CGRAMCHECK_H