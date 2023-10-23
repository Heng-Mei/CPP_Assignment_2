#include <iostream>
using namespace std;

#include "CQueue.h"

int main()
{
    CQueue cq(3, 2);

    string tempString;
    cin >> tempString ;
    cq.in(tempString);
    cq.in(tempString);
    cq.in(tempString);
    cq.in(tempString);

    cq.out(tempString);
    cout << "tempString = " << tempString << endl;

    cq.out(tempString);
    cout << "tempString = " << tempString << endl;


    //(1)定义CGramCheck对象
    //(2)打开文件（若出错，则提示，并程序结束返回）
    //(3)读入文件内容，检查语法，并保存语法检查结果
    //(4)输出检查结果
    //(5)关闭文件
    return 0;
}
