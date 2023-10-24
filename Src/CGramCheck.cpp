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
        char newLine[1024];
        this->file.getline(newLine, 1024);
        // 将读取的行转换为string
        string line = newLine;
        // TODO 一行入队并开始语法检查
    }
}