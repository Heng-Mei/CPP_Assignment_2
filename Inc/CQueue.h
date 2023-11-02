/*
 * @Date: 2023-10-23 16:11:50
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-11-02 15:44:34
 * @FilePath: \Assignment_2\Inc\CQueue.h
 */
#ifndef CQUEUE_H
#define CQUEUE_H

#include <string>
#include <map>
using namespace std;

class CQueue
{
private:
    string *m_pBuf;
    int m_nSize;
    int m_nIncStep;

public:
    CQueue(int nInitSize, int nIncStep);   // 初始大小，队列增长步长；
    CQueue(const CQueue &cq);              // 拷贝构造函数
    CQueue(const string &line);            // 使用字符串直接构造队列
    CQueue &operator=(const CQueue &cq);   // 运算符重载
    CQueue &operator=(const string &line); // 使用字符串直接对队列复制
    virtual ~CQueue();                     // 释放内存
    bool in(const string &ele);            // 单词如队，若当前存储区不足，自动增长（步长为m_nIncStep），入队成功返回true。
    bool out(string &ele);                 // 队头单词出队，若队列空，返回false。
    int size() const;                      // 队列内当前的元素个数
    // 其他必要成员函数（自定义）
    bool extend(int step);
    void extend(void);
    void clear(void);
    bool isEmpty(void) const;
    bool isFull(void) const;
    void outPrint(void);
    void inLine(const string &line);
    void outLine(void);
    static bool isLetter(char ch);
    map<string, int> toMap(void);
};

inline CQueue::CQueue(int nInitSize = 10, int nIncStep = 5) : m_nSize(nInitSize), m_nIncStep(nIncStep)
{
    m_pBuf = new string[m_nSize];
}

inline CQueue::CQueue(const CQueue &cq)
{
    this->m_nIncStep = cq.m_nIncStep;
    this->m_nSize = cq.m_nSize;
    this->m_pBuf = new string[this->m_nSize];
    for (int i = 0; i < this->m_nSize; i++)
    {
        this->m_pBuf[i] = cq.m_pBuf[i];
    }
}

inline CQueue::CQueue(const string &line) : m_nSize(10), m_nIncStep(5)
{
    this->m_pBuf = new string[this->m_nSize];
    this->inLine(line);
}

inline CQueue &CQueue::operator=(const CQueue &cq)
{
    if (this != &cq)
    {
        this->m_nIncStep = cq.m_nIncStep;
        this->m_nSize = cq.m_nSize;
        delete[] this->m_pBuf;
        this->m_pBuf = new string[this->m_nSize];
        for (int i = 0; i < this->m_nSize; i++)
        {
            this->m_pBuf[i] = cq.m_pBuf[i];
        }
    }
    return *this;
}

inline CQueue &CQueue::operator=(const string &line)
{
    this->clear();
    this->inLine(line);
    return *this;
}

inline CQueue::~CQueue()
{
    delete[] m_pBuf;
}

#endif // CQUEUE_H