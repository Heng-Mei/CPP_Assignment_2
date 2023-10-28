/*
 * @Date: 2023-10-24 15:15:50
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-10-28 21:30:51
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
        this->checkPair(lineQueue, "{", "}");
        this->checkPair(lineQueue, "(", ")");
        this->checkPair(lineQueue, "'", "'");
        this->checkPair(lineQueue, "/*", "*/");
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
    // 打印开始输出结果的信息
    cout << "Start to output the result." << endl;
    // 打开文件
    ofstream outFile;
    outFile.open(fileName, ios::in);
    // 如果文件存在，则覆盖
    if (outFile.is_open() == true)
    {
        cout << "The file exists, and the file will be overwritten." << endl;
        outFile.close();
    }
    // 打开文件，以写入的方式
    outFile.open(fileName, ios::out);
    // 写入文件名
    outFile << "The file name is: " << fileName << endl;
    outFile << endl;
    // 写入行数
    outFile << "The line count is: " << this->lineCount << endl;
    outFile << endl;

    // TODO 写入配对结果
    
    // 写入semicolon结果
    outFile << "The semicolon result is: " << endl;
    // 初始化semicolonTotalFlag为false
    bool semicolonTotalFlag = false;
    // 遍历semicolonResult，写入文件
    for (int i = 0; i < this->semicolonResult.size(); i++)
    {
        // 如果当前行没有semicolon，则写入Missing semicolon的信息
        if (semicolonResult[i] == 1)
        {
            outFile << "Line " << i + 1 << ": "
                    << "Missing semicolon." << endl;
            semicolonTotalFlag = true;
        }
        // 如果当前行有extra semicolon，则写入Extra semicolon的信息
        else if (semicolonResult[i] == -1)
        {
            outFile << "Line " << i + 1 << ": "
                    << "Extra semicolon." << endl;
            semicolonTotalFlag = true;
        }
    }
    // 如果semicolonTotalFlag为false，则表示所有行没有semicolon problem
    if (semicolonTotalFlag == false)
    {
        outFile << "All lines: "
                << "OK." << endl;
    }

    // 关闭文件
    outFile.close();
}

/**
 * @description: 检查某一行的分号情况
 * @param {CQueue} line
 * @return {int} -1:多余分号 0:OK 1:缺少分号
 */
int CGramCheck::checkSemicolon(CQueue line)
{
    // 如果队列为空，则返回0
    if (line.size() == 0)
    {
        return 0;
    }

    // 定义一个布尔变量，用来判断是否有分号
    bool semicolonCount = false;
    // 定义一个布尔变量，用来判断是否该有分号
    bool semicolonFlag = true;
    // 定义一个字符串变量，用来存储临时字符串
    string tempWord;
    // 循环遍历队列
    while (line.isEmpty() == false)
    {
        // 从队列中取出一个字符串
        line.out(tempWord);
        // 如果字符串是#，则将semicolonFlag设置为false
        if (tempWord == "#")
        {
            semicolonFlag = false;
        }

        // 如果字符串是{、}、(、)，则将semicolonFlag设置为false
        if (tempWord == "{" || tempWord == "}" || tempWord == "(" || tempWord == ")")
        {
            semicolonFlag = false;
        }

        // 如果字符串是;，则将semicolonCount设置为true
        if (tempWord == ";")
        {
            semicolonCount = true;
        }
    }

    // 如果semicolonCount为true，且semicolonFlag为false，则返回-1
    if (semicolonCount == true && semicolonFlag == false)
    {
        return -1;
    }
    // 如果semicolonCount为false，且semicolonFlag为true，则返回1
    else if (semicolonCount == false && semicolonFlag == true)
    {
        return 1;
    }

    // 否则，返回0
    return 0;
}

/**
 * @description: 数一个队列中某个字符串的数量
 * @param {CQueue} line
 * @param {string} &word 待计数字符'{}'等
 * @return {int} 字符出现次数
 */
int CGramCheck::countWord(CQueue line, const string &word)
{
    // 定义一个计数器
    int count = 0;
    // 当队列不为空时，循环执行
    while (line.isEmpty() == false)
    {
        // 定义一个临时变量，用于存储出队元素
        string tempWord;
        // 将队列中的元素出队
        line.out(tempWord);
        // 如果出队元素和word相等，计数器加1
        if (tempWord == word)
        {
            count++;
        }
    }
    // 返回计数器
    return count;
}

/**
 * @description: 检查某个字符的配对
 * @param {CQueue} line
 * @param {string} &left { (
 * @param {string} &right } )
 * @return {void}
 */
void CGramCheck::checkPair(CQueue line, const string &left, const string &right)
{
    // 定义一个结果数组
    vector<int> pairResult;
    // 定义一个计数器
    int leftCount = CGramCheck::countWord(line, left);
    int rightCount = CGramCheck::countWord(line, right);
    // 将计数器放入结果数组
    pairResult.push_back(leftCount);
    pairResult.push_back(rightCount);

    // 判断左右括号是否匹配
    if (left == "(" && right == ")")
    {
        // 将计数器放入结果数组
        this->parenthesesResult[1] += pairResult[0];
        this->parenthesesResult[2] += pairResult[1];
        // 判断左右括号是否匹配
        parenthesesResult[0] = parenthesesResult[1] == parenthesesResult[2] ? 0 : 1;
    }
    else if (left == "{" && right == "}")
    {
        // 将计数器放入结果数组
        this->braceResult[1] += pairResult[0];
        this->braceResult[2] += pairResult[1];
        // 判断左右括号是否匹配
        braceResult[0] = braceResult[1] == braceResult[2] ? 0 : 1;
    }
    else if (left == "'" && right == "'")
    {
        // 将计数器放入结果数组
        this->quotationResult[1] += pairResult[0];
        this->quotationResult[2] += pairResult[1];
        // 判断左右引号是否匹配
        quotationResult[0] = quotationResult[1] == quotationResult[2] ? 0 : 1;
    }
    else if (left == "/*" && right == "*/")
    {
        // 将计数器放入结果数组
        this->commentResult[1] += pairResult[0];
        this->commentResult[2] += pairResult[1];
        // 判断左右注释是否匹配
        commentResult[0] = commentResult[1] == commentResult[2] ? 0 : 1;
    }
}
