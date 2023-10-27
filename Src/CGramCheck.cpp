/*
 * @Date: 2023-10-24 15:15:50
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-10-27 16:39:20
 * @FilePath: \Assignment_2\Src\CGramCheck.cpp
 */
#include "CGramCheck.h"

/**
 * @description: 打开CPP文件
 * @param {char} *fileName 文件名
 * @return {bool} 返回是否打开成功
 */
bool CGramCheck::openCPP(const char *fileName)
{
    // 打开文件
    this->file.open(fileName, ios::in);
    // 返回文件是否打开
    return this->file.is_open();
}

/**
 * @description: 语法检查
 * @return {void}
 */
void CGramCheck::checkGram(void)
{
    // 检查文件是否打开
    if (this->file.is_open() == false)
    {
        cerr << "The file has not been opened." << endl;
        return;
    }

    // 循环检查文件中的每一行
    while (this->file.eof() == false)
    {
        // // 读取一行
        string line;
        getline(this->file, line);
        cout << line << endl;
        // TODO 一行入队并开始语法检查
        CQueue lineQueue;
        lineQueue.inLine(line);
        this->semicolonResult.push_back(CGramCheck::checkSemicolon(lineQueue));
        lineQueue.inLine(line);
        lineQueue.outLine();
        this->lineCount++;
    }
}

/**
 * @description: 输出结果
 * @param {char} *fileName
 * @return {void}
 */
void CGramCheck::outLog(const char *fileName)
{
    cout << "Start to output the result." << endl;
    // 打开文件
    ofstream outFile;
    outFile.open(fileName, ios::in);
    if (outFile.is_open() == true)
    {
        cout << "The file exists, and the file will be overwritten." << endl;
        outFile.close();
    }
    outFile.open(fileName, ios::out);
    // 输出结果
    outFile << "The file name is: " << fileName << endl;
    outFile << endl;
    outFile << "The line count is: " << this->lineCount << endl;
    outFile << endl;
    outFile << "The semicolon result is: " << endl;

    bool semicolonTotalFlag = false;
    for (auto &&i : this->semicolonResult)
    {
        if (i == 1)
        {
            outFile << "Line " << this->lineCount << ": "
                    << "Missing semicolon." << endl;
            semicolonTotalFlag = true;
        }
        else if (i == -1)
        {
            outFile << "Line " << this->lineCount << ": "
                    << "Extra semicolon." << endl;
            semicolonTotalFlag = true;
        }
    }
    if (semicolonTotalFlag == false)
    {
        outFile << "All lines: "
                << "OK." << endl;
    }

    outFile.close();
}

/**
 * @description: 检查某一行的分号情况
 * @param {CQueue} line
 * @return {int} -1:多余分号 0:OK 1:缺少分号
 */
int CGramCheck::checkSemicolon(CQueue &line)
{
    if (line.size() == 0)
    {
        return 0;
    }

    bool semicolonCount = false;
    bool semicolonFlag = true;
    string tempWord;
    while (line.isEmpty() == false)
    {
        line.out(tempWord);
        if (tempWord == "#")
        {
            semicolonFlag = false;
        }

        if (tempWord == "{" || tempWord == "}" || tempWord == "(" || tempWord == ")")
        {
            semicolonFlag = false;
        }

        if (tempWord == ";")
        {
            semicolonCount = true;
        }
    }

    if (semicolonCount == true && semicolonFlag == false)
    {
        return -1;
    }
    else if (semicolonCount == false && semicolonFlag == true)
    {
        return 1;
    }
    
    return 0;
}
