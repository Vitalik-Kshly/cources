#pragma once
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


class Scanner
{
public:
    Scanner(string path);
    void ChangePath(string path);
    void ScanFile();
    ~Scanner();
    void GetData(int &_emptyLines, int& _codeLines, int& _commentLines);
    void PrintData();
private:
    bool _lineContainsCode(string line, bool inCommentBlock = false);
    void _printLine(string line = "");
    string _filePath;
    fstream _fileStream;
    int _emptyLines, _codeLines, _commentLines;

};