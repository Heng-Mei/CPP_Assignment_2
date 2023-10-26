/*
 * @Date: 2023-10-24 21:07:00
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-10-26 12:52:26
 * @FilePath: \Assignment_2\main.cpp
 */
#include <iostream>
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

    CGramCheck gc;
    if (gc.openCPP("./Res/tobecheck.cpp") == false)
    {
        cerr << "The file not be found!" << endl;
        return 0;
    }

    gc.checkGram();
    
    gc.outLog("./Res/checkres.txt");
    
    //(1)定义CGramCheck对象
    //(2)打开文件（若出错，则提示，并程序结束返回）
    //(3)读入文件内容，检查语法，并保存语法检查结果
    //(4)输出检查结果
    //(5)关闭文件
    return 0;
}
