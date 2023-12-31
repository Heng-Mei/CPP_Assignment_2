<!--
 * @Date: 2023-10-23 14:42:02
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-11-03 14:54:40
 * @FilePath: \Assignment_2\README.md
-->
# 作业要求
## 基本功能
---
- [x] 自定义队列类类型，主要数据成员类型为string，该类主要用于保存源文件各行中拆分出来的单词。
---
- [ ] 能够完成基本的C++语法检查
  -   [x]   必选
      -   [x]   花括号配对
      -   [x]   分号缺失情况
      -   [x]   运算符符合运算规则情况
      -   [x]   引号（单双配对情况）
      -   [x]   块内注释情况（/* */）
      -   [x]   圆括号匹配情况
  -   [ ]   可选（**加分项**）
      -   [ ]   函数调用与函数定义不匹配情况（实参形参不匹配，函数为自定义函数：`void customFunc(int*, int)`。）
      -   [ ]   其他情况。
      -   [ ]   能够检查的语法不符情况多则加分。
---
##  测试流程
```c++
int main()
{
    //(1)定义CGramCheck对象
    //(2)打开文件（若出错，则提示，并程序结束返回）
    //(3)读入文件内容，检查语法，并保存语法检查结果
    //(4)输出检查结果
    //(5)关闭文件
    return 0;
}
``` 
##  类声明
```c++
// 该类主要用于保存源文件各行中拆分出来的单词
class CQueue
{
private:
    string *m_pBuf;
    int m_nSize;
    int m_nIncStep;

public:
    CQueue(int nInitSize, int nIncStep); // 初始大小，队列增长步长；
    ~CQuue();                            // 释放内存
    bool in(string ele);                 // 单词如队，若当前存储区不足，自动增长（步长为m_nIncStep），入队成功返回true。
    bool out(string &ele);               // 队头单词出队，若队列空，返回false。
    int size();                          // 队列内当前的元素个数
    // 其他必要成员函数（自定义）
};
``` 
##  其他要求
-   [x]   输出的结果文件中应包含
    -   [x]   待检查文件总行数
    -   [x]   检查出的语法问题总数及分类问题数量，分类问题列出的顺序参见[基本功能](#基本功能)
-   [x]   要求将主要代码定义为一个类，类名称`CGramCheck`
-   [x]   要求有异常处理逻辑（主要是打开文件部分）
-   [x]   若默认的待检测文件不存在，安全退出，并提示
-   [x]   若默认的检查结果文件已经存在，则删除（或清空其内容）
-   [x]   待检查源文件(`tobecheck.cpp`)由老师提供
-   [x]   要求独立完成，抄袭将被扣分或不得分

#   文件目录
-   Inc
    -   `CQueue.h`
    >   类及其成员函数声明 
-   Src
    -   `CQueue.cpp`
    >   类成员函数定义
-   Res
    -   `tobecheck.cpp`
    >   待检查语法文件
    -   `checkres.txt`
    >   检查结果输出文件
-   main.cpp
>   测试主程序
-   README.md 
