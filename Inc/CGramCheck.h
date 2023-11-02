/*
 * @Date: 2023-10-24 15:13:25
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-11-02 15:56:00
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

private:
    static int checkSemicolon(map<string, int> &times);
    // static int countWord(CQueue line, const string &word);
    void checkPair(map<string, int> &times, const string &left, const string &right);
    void outPair(ofstream &outFile, const string &left, const string &right) const;
    void checkLine(CQueue &line);

public:
    CGramCheck(const char *fileName);
    CGramCheck();
    virtual ~CGramCheck();
    bool openCPP(const char *fileName);
    void checkGram(void);
    void outLog(const char *fileName);
    static void outPrintFile(const char *fileName);
};

inline CGramCheck::CGramCheck(const char *fileName) : lineCount(0), commentResult(3, 0), braceResult(3, 0), parenthesesResult(3, 0), quotatesResult(3, 0), doubleQuotesResult(3, 0)
{
    if (this->openCPP(fileName) == false)
    {
        cerr << "The file not be found!" << endl;
        return;
    }
}

inline CGramCheck::CGramCheck() : lineCount(0), commentResult(3, 0), braceResult(3, 0), parenthesesResult(3, 0), quotatesResult(3, 0), doubleQuotesResult(3, 0)
{
}

inline CGramCheck::~CGramCheck()
{
    // 关闭文件
    this->file.close();
}

#endif // CGRAMCHECK_H