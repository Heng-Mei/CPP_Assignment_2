/*
 * @Date: 2023-10-23 16:18:42
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-10-23 21:37:24
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
bool CQueue::in(string ele)
{
    if (this->size() == this->m_nSize)
    {
        this->extend();
    }
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
    int cqSize = this->size();
    if (cqSize == 0)
    {
        return false;
    }
    ele = m_pBuf[0];
    for (int i = 0; i < cqSize; i++)
    {
        m_pBuf[i] = m_pBuf[i + 1];
    }
    return true;
}

/**
 * @description: 返回队列内当前的元素个数
 * @return {int} 队列内当前的元素个数
 */
int CQueue::size() const
{
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
    if (step <= 0)
    {
        return false;
    }
    string *newPtr = new string[this->m_nSize + step];
    for (int i = 0; i < this->m_nSize; i++)
    {
        newPtr[i] = this->m_pBuf[i];
    }
    delete[] this->m_pBuf;
    this->m_pBuf = newPtr;
    this->m_nSize += step;
    return true;
}

/**
 * @description: 增加IncStep的长度
 * @return {*}
 */
void CQueue::extend(void)
{
    this->extend(this->m_nIncStep);
}
