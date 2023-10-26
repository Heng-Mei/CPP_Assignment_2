/*
 * @Date: 2023-10-24 15:15:50
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-10-26 20:43:47
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
    outFile << "The line count is: " << this->lineCount << endl;
    outFile.close();
}
