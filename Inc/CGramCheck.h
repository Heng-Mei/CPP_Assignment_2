/*
 * @Date: 2023-10-24 15:13:25
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-10-26 12:49:38
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
    int lineCount;
    fstream file;

public:
    CGramCheck(const char *fileName);
    CGramCheck();
    ~CGramCheck();
    bool openCPP(const char *fileName);
    void checkGram(void);
    void outLog(const char *fileName);
};

inline CGramCheck::CGramCheck(const char *fileName) : lineCount(0)
{
    if (this->openCPP(fileName) == false)
    {
        cerr << "The file not be found!" << endl;
        return;
    }
}

inline CGramCheck::CGramCheck() : lineCount(0)
{
}

inline CGramCheck::~CGramCheck()
{
    // 关闭文件
    this->file.close();
}

#endif // CGRAMCHECK_H