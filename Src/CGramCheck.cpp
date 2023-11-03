/*
 * @Date: 2023-10-24 15:15:50
 * @LastEditors: Heng-Mei l888999666y@gmail.com
 * @LastEditTime: 2023-11-03 14:38:29
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
        // 读取一行
        string line;
        getline(this->file, line);
        // 创建一个行队列
        CQueue lineQueue = line;

        this->checkLine(lineQueue);

        // 行计数器
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
    cout << "Starting to write results." << endl;
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

    // 写入花括号配对结果
    this->outPair(outFile, "{", "}");

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
    outFile << endl;

    // 写入operator结果
    outFile << "The operator result is: " << endl;
    bool operatorTotalFlag = false;
    for (int i = 0; i < this->operatorResult.size(); i++)
    {
        if (this->operatorResult[i].size() != 0)
        {
            operatorTotalFlag = true;
            outFile << "Line " << i + 1 << ": "
                    << "Operator problem: " << this->operatorResult[i] << endl;
        }
    }
    // 如果 operatorTotalFlag 为 false，则表示所有行没有 operator problem
    if (operatorTotalFlag == false)
    {
        outFile << "All lines: "
                << "OK." << endl;
    }
    outFile << endl;

    // 写入单引号配对结果
    this->outPair(outFile, "'", "'");

    // 写入双引号配对结果
    this->outPair(outFile, "\"", "\"");

    // 写入注释块配对结果
    this->outPair(outFile, "/*", "*/");

    // 写入圆括号配对结果
    this->outPair(outFile, "(", ")");

    // 关闭文件
    outFile.close();
}

/**
 * @description: 检查某一行的分号情况
 * @param {map<string, int>} &times
 * @return {int} -1:多余分号 0:OK 1:缺少分号
 */
int CGramCheck::checkSemicolon(map<string, int> &times)
{
    // // 如果队列为空，则返回0
    // if (line.size() == 0)
    // {
    //     return 0;
    // }

    // // 定义一个布尔变量，用来判断是否有分号
    // bool semicolonCount = false;
    // // 定义一个布尔变量，用来判断是否该有分号
    // bool semicolonFlag = true;
    // // 定义一个字符串变量，用来存储临时字符串
    // string tempWord;
    // // 循环遍历队列
    // while (line.isEmpty() == false)
    // {
    //     // 从队列中取出一个字符串
    //     line.out(tempWord);
    //     // 如果字符串是#，则将semicolonFlag设置为false
    //     if (tempWord == "#")
    //     {
    //         semicolonFlag = false;
    //     }

    //     // 如果字符串是{、}、(、)，则将semicolonFlag设置为false
    //     if (tempWord == "{" || tempWord == "}" || tempWord == "(" || tempWord == ")")
    //     {
    //         semicolonFlag = false;
    //     }

    //     if (tempWord == "/*" || tempWord == "*/")
    //     {
    //         semicolonFlag = false;
    //     }

    //     // 如果字符串是;，则将semicolonCount设置为true
    //     if (tempWord == ";")
    //     {
    //         semicolonCount = true;
    //     }
    // }

    // // 如果semicolonCount为true，且semicolonFlag为false，则返回-1
    // if (semicolonCount == true && semicolonFlag == false)
    // {
    //     return -1;
    // }
    // // 如果semicolonCount为false，且semicolonFlag为true，则返回1
    // else if (semicolonCount == false && semicolonFlag == true)
    // {
    //     return 1;
    // }

    // // 否则，返回0
    // return 0;

    if (times.empty() == true)
    {
        return 0;
    }

    int semicolonCount = times[";"];
    bool semicolonFlag = true;

    // 检查是否有#
    if (times["#"] >= 1)
    {
        semicolonFlag = false;
    }

    // 检查是否有括号
    if (times["{"] >= 1 || times["}"] >= 1)
    {
        semicolonFlag = false;
    }

    if (times["main"] == 1)
    {
        semicolonFlag = false;
    }

    if (times["if"] == 1)
    {
        semicolonFlag = false;
    }

    if (times["while"] == 1)
    {
        semicolonFlag = false;
    }

    if (times["//"] == 1)
    {
        semicolonFlag = false;
    }

    // 分号数量大于1
    if (semicolonCount > 1)
    {
        return -1;
    }
    // 不应有分号多分号
    else if (semicolonCount == 1 && semicolonFlag == false)
    {
        return -1;
    }
    // 应有分号无分号
    else if (semicolonCount == 0 && semicolonFlag == true)
    {
        return 1;
    }

    return 0;
}

// /**
//  * @description: 数一个队列中某个字符串的数量
//  * @param {CQueue} line
//  * @param {string} &word 待计数字符'{}'等
//  * @return {int} 字符出现次数
//  */
// int CGramCheck::countWord(CQueue line, const string &word)
// {
//     // 定义一个计数器
//     int count = 0;
//     // 当队列不为空时，循环执行
//     while (line.isEmpty() == false)
//     {
//         // 定义一个临时变量，用于存储出队元素
//         string tempWord;
//         // 将队列中的元素出队
//         line.out(tempWord);
//         // 如果出队元素和word相等，计数器加1
//         if (tempWord == word)
//         {
//             count++;
//         }
//     }
//     // 返回计数器
//     return count;
// }

/**
 * @description: 检查某个字符的配对
 * @param {CQueue} line
 * @param {string} &left { (
 * @param {string} &right } )
 * @return {void}
 */
void CGramCheck::checkPair(map<string, int> &times, const string &left, const string &right)
{
    // // 定义一个计数器
    // int leftCount = times[left];
    // int rightCount = times[right];

    // // 判断左右括号是否匹配
    // if (left == "(" && right == ")")
    // {
    //     // 将计数器放入结果数组
    //     this->parenthesesResult[1] += leftCount;
    //     this->parenthesesResult[2] += rightCount;
    //     // 判断左右括号是否匹配
    //     parenthesesResult[0] = parenthesesResult[1] == parenthesesResult[2] ? 0 : 1;
    // }
    // else if (left == "{" && right == "}")
    // {
    //     // 将计数器放入结果数组
    //     this->braceResult[1] += leftCount;
    //     this->braceResult[2] += rightCount;
    //     // 判断左右括号是否匹配
    //     braceResult[0] = braceResult[1] == braceResult[2] ? 0 : 1;
    // }
    // else if (left == "'" && right == "'")
    // {
    //     // 将计数器放入结果数组
    //     this->quotatesResult[1] += leftCount;
    //     this->quotatesResult[2] += rightCount;
    //     // 判断单引号是否偶数
    //     quotatesResult[0] = quotatesResult[1] % 2 == 0 ? 0 : 1;
    // }
    // else if (left == "\"" && right == "\"")
    // {
    //     // 将计数器放入结果数组
    //     this->doubleQuotesResult[1] += leftCount;
    //     this->doubleQuotesResult[2] += rightCount;
    //     // 判断双引号是否偶数
    //     doubleQuotesResult[0] = doubleQuotesResult[1] % 2 == 0 ? 0 : 1;
    // }
    // else if (left == "/*" && right == "*/")
    // {
    //     // 将计数器放入结果数组
    //     this->commentResult[1] += leftCount;
    //     this->commentResult[2] += rightCount;
    //     // 判断左右注释是否匹配
    //     commentResult[0] = commentResult[1] == commentResult[2] ? 0 : 1;
    // }
    // else
    // {
    //     cerr << "Unknown character pair: " << left << " " << right << endl;
    //     exit(1);
    // }

    if (left != right)
    {
        this->pairResult[left] += times[left];
        this->pairResult[right] += times[right];
    }
    else
    {
        this->pairResult[left] += times[left];
    }
}

/**
 * @description: 输出某个符号的配对信息
 * @param {ofstream} &outFile 输出文件
 * @param {string} &left { (
 * @param {string} &right } )
 * @return {void}
 */
void CGramCheck::outPair(ofstream &outFile, const string &left, const string &right)
{
    // // 判断左右字符是否为括号
    // if (left == "(" && right == ")")
    // {
    //     outFile << "The parentheses pair result is: " << endl;
    //     // 判断括号是否匹配
    //     if (this->parenthesesResult[0] == 0)
    //     {
    //         outFile << "OK" << endl;
    //     }
    //     else
    //     {
    //         outFile << "There are " << this->parenthesesResult[1] << " '(' "
    //                 << "and " << this->parenthesesResult[2] << " ')' " << endl;
    //     }
    // }
    // // 判断左右字符是否为大括号
    // else if (left == "{" && right == "}")
    // {
    //     outFile << "The brace pair result is: " << endl;
    //     // 判断大括号是否匹配
    //     if (this->braceResult[0] == 0)
    //     {
    //         outFile << "OK" << endl;
    //     }
    //     else
    //     {
    //         outFile << "There are " << this->braceResult[1] << " '{' "
    //                 << "and " << this->braceResult[2] << " '}' " << endl;
    //     }
    // }
    // // 判断左右字符是否为单引号
    // else if (left == "'" && right == "'")
    // {
    //     outFile << "The quotates pair result is: " << endl;
    //     // 判断单引号是否匹配
    //     if (this->quotatesResult[0] == 0)
    //     {
    //         outFile << "OK" << endl;
    //     }
    //     else
    //     {
    //         outFile << "There are " << this->quotatesResult[1] << " ''' "
    //                 << ", and the num isn't even" << endl;
    //     }
    // }
    // // 判断左右字符是否为双引号
    // else if (left == "\"" && right == "\"")
    // {
    //     outFile << "The double quotes pair result is: " << endl;
    //     // 判断双引号是否匹配
    //     if (this->doubleQuotesResult[0] == 0)
    //     {
    //         outFile << "OK" << endl;
    //     }
    //     else
    //     {
    //         outFile << "There are " << this->doubleQuotesResult[1] << " '\"' "
    //                 << ", and the num isn't even" << endl;
    //     }
    // }
    // // 判断左右字符是否为注释
    // else if (left == "/*" && right == "*/")
    // {
    //     outFile << "The comment pair result is: " << endl;
    //     // 判断注释是否匹配
    //     if (this->commentResult[0] == 0)
    //     {
    //         outFile << "OK" << endl;
    //     }
    //     else
    //     {
    //         outFile << "There are " << this->commentResult[1] << " '/*' "
    //                 << "and " << this->commentResult[2] << " '*/' " << endl;
    //     }
    // }
    // // 判断左右字符是否为未知字符
    // else
    // {
    //     cerr << "Unknown character pair: " << left << " " << right << endl;
    //     exit(1);
    // }

    outFile << "The " + left + " " + right + " pair result is: " << endl;
    if (left == right)
    {
        // 如果两个字符相等，则判断其出现次数是否为偶数
        if (this->pairResult[left] % 2 == 0)
        {
            // 如果是偶数，则输出OK
            outFile << "OK" << endl;
        }
        else
        {
            // 如果不是偶数，则输出其出现次数和字符
            outFile << "There are " << pairResult[left] << " " << left
                    << ", and the num isn't even" << endl;
        }
    }
    else
    {
        // 如果两个字符不相等，则判断其出现次数是否相等
        if (this->pairResult[left] == this->pairResult[right])
        {
            // 如果相等，则输出OK
            outFile << "OK" << endl;
        }
        else
        {
            // 如果不相等，则输出其出现次数和字符
            outFile << "There are " << this->pairResult[left] << " '" + left + "' "
                    << "and " << this->pairResult[right] << " '" + right + "' " << endl;
        }
    }
    outFile << endl;
}

/**
 * @description: 读一个文件逐行打印
 * @param {char} *fileName
 * @return {void}
 */
void CGramCheck::outPrintFile(const char *fileName)
{
    // 打开文件
    ifstream inFile;
    inFile.open(fileName);
    // 如果文件打开失败，则输出错误信息并退出
    if (!inFile.is_open())
    {
        cerr << "Can't open file: " << fileName << endl;
        exit(1);
    }

    // 读取文件中的每一行
    string line;
    while (inFile.eof() == false)
    {
        // 读取一行
        getline(inFile, line);
        // 输出到屏幕
        cout << line << endl;
        // 清空line
        line.clear();
    }
    // 关闭文件
    inFile.close();
}

/**
 * @description: 对一行代码进行检查
 * @param {CQueue} &line
 * @return {void}
 */
void CGramCheck::checkLine(CQueue &line)
{
    // 检查运算符
    this->operatorResult.push_back(CGramCheck::checkOperator(line));
    // 将CQueue转换为map<string, int>
    map<string, int> times = line.toMap();
    // 检查分号
    this->semicolonResult.push_back(CGramCheck::checkSemicolon(times));
    // 检查成对符号
    this->checkPair(times, "{", "}");
    this->checkPair(times, "(", ")");
    this->checkPair(times, "'", "'");
    this->checkPair(times, "\"", "\"");
    this->checkPair(times, "/*", "*/");
}

/**
 * @description: 关闭CPP文件
 * @return {void}
 */
void CGramCheck::closeCPP()
{
    // 关闭CPP文件
    this->file.close();
}

/**
 * @description: 判断一个字符串是否是单词
 * @param {string} &word
 * @return {bool} 是返回1
 */
bool CGramCheck::isWord(const string &word)
{
    for (auto &&ch : word)
    {
        // 检查字符是否为字母
        if (CQueue::isLetter(ch) == false)
        {
            // 如果不是字母，返回false
            return false;
        }
    }
    // 如果都是字母，返回true
    return true;
}

/**
 * @description: 判断一个字符串是否是运算符
 * @param {string} &word
 * @return {bool} 是返回1
 */
bool CGramCheck::isOperator(const string &word)
{
    if (word == "=" || word == "+" || word == "-" || word == "*" || word == "/" || word == "%" || word == ">=" || word == "<=" || word == "==")
    {
        return true;
    }
    return false;
}

/**
 * @description: 判断一个字符串是否是数字
 * @param {string} &word
 * @return {bool} 是返回1
 */
bool CGramCheck::isNum(const string &word)
{
    for (auto &&ch : word)
    {
        if (ch != '.' && (ch < '0' || ch > '9'))
        {
            return false;
        }
    }
    return true;
}

/**
 * @description: 检查一行中是否存在运算符错误
 * @param {CQueue} line
 * @return {string} 返回出错的运算符
 */
string CGramCheck::checkOperator(CQueue line)
{
    string preWord, curWord, postWord;
    line.out(curWord);
    preWord = curWord;
    while (line.isEmpty() == false)
    {
        // 判断当前单词是否是操作符
        if (CGramCheck::isOperator(curWord) == true)
        {
            // 判断当前操作符是否是左操作符
            if (preWord != ")" && !CGramCheck::isWord(preWord) && !CGramCheck::isNum(preWord))
            {
                // 不是左操作符，返回当前操作符
                return curWord;
            }
            // 判断是否是最后一个单词
            if (line.isEmpty() == true)
            {
                // 最后一个单词，返回当前操作符
                return curWord;
            }
            // 读取下一个单词
            line.out(postWord);
            // 判断下一个单词是否是右操作符
            if (postWord != "(" && !CGramCheck::isWord(postWord) && !CGramCheck::isNum(postWord))
            {
                // 不是右操作符，返回当前操作符
                return curWord;
            }
            preWord = curWord;
            curWord = postWord;
            continue;
        }
        preWord = curWord;
        // 读取当前单词
        line.out(curWord);
    }
    return "";
}