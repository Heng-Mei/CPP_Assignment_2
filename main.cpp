/*
 * @Date: 2023-10-24 21:07:00
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-11-03 14:59:31
 * @FilePath: \Assignment_2\main.cpp
 */
#include <iostream>
#include <algorithm>
using namespace std;

#include "CQueue.h"
#include "CGramCheck.h"

int main()
{
    /* CQueue cq(3, 2);

    cq.in("hello");
    cq.in("world");
    cq.in("good");
    cq.in("morning");

    cq.outPrint();
    cq.outPrint();
    cq.outPrint();
    cq.outPrint();
    cq.outPrint(); */

    //(0)读入路径和输出路径设置
    const char *inputPath = "./Res/tobecheck.cpp";
    // const char *inputPath = "./Res/OK.cpp";
    const char *outputPath = "./Res/checkres.txt";

    //(1)定义CGramCheck对象
    CGramCheck gc;

    //(2)打开文件（若出错，则提示，并程序结束返回）
    if (gc.openCPP(inputPath) == false)
    {
        cerr << "The file not be found!" << endl;
        return 0;
    }

    //(3)读入文件内容，检查语法，并保存语法检查结果
    gc.checkGram();
    gc.outLog(outputPath);

    //(4)输出检查结果
    cout << "--------------------" << endl;
    cout << "The file content is:" << endl;
    CGramCheck::outPrintFile(inputPath);
    cout << "--------------------" << endl;
    cout << "The check result is:" << endl;
    CGramCheck::outPrintFile(outputPath);

    //(5)关闭文件
    gc.closeCPP();
    return 0;
}
