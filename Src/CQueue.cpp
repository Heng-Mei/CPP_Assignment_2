/*
 * @Date: 2023-10-23 16:18:42
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-10-25 18:32:12
 * @FilePath: \Assignment_2\Src\CQueue.cpp
 */
#include "CQueue.h"

#include <iostream>
using namespace std;

/**
 * @description: 单词入队，若当前存储区不足，自动增长（步长为m_nIncStep）
 * @param {string} ele
 * @return {bool} 入队成功返回true。
 */
bool CQueue::in(const string &ele)
{
    if (ele.size() == 0)
    {
        return true;
    }
    // 如果队列已满，则扩展队列
    if (this->isFull())
    {
        this->extend();
    }
    // 将元素ele放入队列
    m_pBuf[this->size()] = ele;
    return true;
}

/**
 * @description: 队头单词出队
 * @param {string} &ele
 * @return {bool} 若队列空，返回false。
 */
bool CQueue::out(string &ele)
{
    // 获取队列大小
    int cqSize = this->size();
    // 如果队列为空，则返回false
    if (this->size() == 0)
    {
        return false;
    }
    // 将队列第一个元素赋值给ele
    ele = m_pBuf[0];
    // 循环遍历队列，将队列元素向前移动一个位置
    for (int i = 0; i < cqSize; i++)
    {
        m_pBuf[i] = m_pBuf[i + 1];
    }
    // 返回true
    return true;
}

/**
 * @description: 返回队列内当前的元素个数
 * @return {int} 队列内当前的元素个数
 */
int CQueue::size() const
{
    // 遍历m_nSize次，每次取出一个字符串，如果字符串长度为0，则返回该字符串的索引，否则返回m_nSize
    for (int i = 0; i < m_nSize; i++)
    {
        if (m_pBuf[i].size() == 0)
        {
            return i;
        }
    }
    return m_nSize;
}

/**
 * @description: 增加step的长度
 * @param {int} step
 * @return {bool} 检查步长是否大于0
 */
bool CQueue::extend(int step)
{
    // 如果扩展步数小于等于0，则返回false
    if (step <= 0)
    {
        return false;
    }
    // 创建一个新的字符串数组，大小为当前数组大小加上扩展步数
    string *newPtr = new string[this->m_nSize + step];
    // 将当前数组中的元素复制到新数组中
    for (int i = 0; i < this->m_nSize; i++)
    {
        newPtr[i] = this->m_pBuf[i];
    }
    // 释放当前指针分配的空间
    delete[] this->m_pBuf;
    // 更新地址
    this->m_pBuf = newPtr;
    // 更新大小
    this->m_nSize += step;
    // 返回true
    return true;
}

/**
 * @description: 增加IncStep的长度
 * @return {void}
 */
void CQueue::extend(void)
{
    // 扩展m_nIncStep步
    this->extend(this->m_nIncStep);
}

/**
 * @description: 清空队列
 * @return {void}
 */
void CQueue::clear(void)
{
    // 删除m_pBuf指针指向的内存空间
    delete[] this->m_pBuf;
    // 重新分配m_pBuf指针指向的内存空间
    this->m_pBuf = new string[this->m_nSize];
}

/**
 * @description: 判断队列是否为空
 * @return {bool} 空返回true
 */
bool CQueue::isEmpty(void) const
{
    // 判断队列是否为空
    return this->size() == 0;
}

/**
 * @description: 判断队列是否满了
 * @return {bool} 满了返回true
 */
bool CQueue::isFull(void) const
{
    // 返回队列大小是否等于队列容量
    return this->size() == this->m_nSize;
}

/**
 * @description: 出队并输出
 * @return {void}
 */
void CQueue::outPrint(void)
{
    // 定义临时字符串
    string tempString;
    // 出队是否成功
    if (this->out(tempString))
    {
        cout << tempString << endl;
    }
    else
    {
        cout << "The Queue is empty!" << endl;
    }
}

/**
 * @description: 读入一行入队
 * @param {string} &line
 * @return {void}
 */
void CQueue::inLine(const string &line)
{
    // 定义一个临时变量
    string tempWord;
    // 遍历字符串中的每一个字符
    for (auto &&ch : line)
    {
        // 如果当前字符是空格或者当前字符是最后一个字符
        if (ch == ' ' || &ch == &line.back())
        {
            if (ch != ' ')
            {
                tempWord += ch;
            }
            // 调用in函数，将临时变量中的字符串传入
            this->in(tempWord);
            // 将临时变量清空
            tempWord.clear();
        }
        // 否则，将当前字符添加到临时变量中
        else
        {
            tempWord += ch;
        }
    }
}

/**
 * @description: 出队所有元素并输出
 * @return {void}
 */
void CQueue::outLine(void)
{
    while (this->isEmpty() == false)
    {
        this->outPrint();
    }
}