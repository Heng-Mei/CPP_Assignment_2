/*
 * @Date: 2023-10-24 15:13:25
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-10-29 16:31:10
 * @FilePath: \Assignment_2\Inc\CGramCheck.h
 */
#ifndef CGRAMCHECK_H
#define CGRAMCHECK_H

#include "CQueue.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class CGramCheck
{
private:
    int lineCount;
    vector<int> semicolonResult;
    vector<int> commentResult;      // /* */
    vector<int> braceResult;        // {}
    vector<int> parenthesesResult;  // ()
    vector<int> quotatesResult;     // ''
    vector<int> doubleQuotesResult; // ""
    fstream file;

public:
    CGramCheck(const char *fileName);
    CGramCheck();
    ~CGramCheck();
    bool openCPP(const char *fileName);
    void checkGram(void);
    void outLog(const char *fileName);
    static int checkSemicolon(CQueue line);
    static int countWord(CQueue line, const string &word);
    void checkPair(CQueue line, const string &left, const string &right);
    void outPair(ofstream &outFile, const string &left, const string &right) const;
};

inline CGramCheck::CGramCheck(const char *fileName) : lineCount(0)
{
    if (this->openCPP(fileName) == false)
    {
        cerr << "The file not be found!" << endl;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        commentResult.push_back(0);
        braceResult.push_back(0);
        parenthesesResult.push_back(0);
        quotatesResult.push_back(0);
        doubleQuotesResult.push_back(0);
    }
}

inline CGramCheck::CGramCheck() : lineCount(0)
{
    for (int i = 0; i < 3; i++)
    {
        commentResult.push_back(0);
        braceResult.push_back(0);
        parenthesesResult.push_back(0);
        quotatesResult.push_back(0);
        doubleQuotesResult.push_back(0);
    }
}

inline CGramCheck::~CGramCheck()
{
    // 关闭文件
    this->file.close();
}

#endif // CGRAMCHECK_H