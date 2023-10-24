/*
 * @Date: 2023-10-23 16:11:50
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-10-24 13:15:20
 * @FilePath: \Assignment_2\Inc\CQueue.h
 */
#ifndef CQUEUE_H
#define CQUEUE_H

#include <string>
using namespace std;

class CQueue
{
private:
    string *m_pBuf;
    int m_nSize;
    int m_nIncStep;

public:
    CQueue(int nInitSize, int nIncStep); // 初始大小，队列增长步长；
    ~CQueue();                           // 释放内存
    bool in(string ele);                 // 单词如队，若当前存储区不足，自动增长（步长为m_nIncStep），入队成功返回true。
    bool out(string &ele);               // 队头单词出队，若队列空，返回false。
    int size() const;                    // 队列内当前的元素个数
    // 其他必要成员函数（自定义）
    bool extend(int step);
    void extend(void);
    void clear(void);
    bool isEmpty(void) const;
    bool isFull(void) const;
    void outPrint(void);
};

inline CQueue::CQueue(int nInitSize, int nIncStep) : m_nSize(nInitSize), m_nIncStep(nIncStep)
{
    m_pBuf = new string[m_nSize]; 
}

inline CQueue::~CQueue()
{
    delete[] m_pBuf;
}

#endif // CQUEUE_H