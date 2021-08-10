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
private:
    size_t _indexOfInlineComment(string line);
    size_t _indexOfComment(string line);
    size_t _indexOfCode(string line);
    bool _lineContainsCode(string line, size_t IndexOfCode, size_t  IndexOfInlineComment, size_t IndexOfComment, size_t IndexOfCloseComment);
    string _filePath;
    ofstream _out;
    fstream _fileStream;
    int _emptyLines, _codeLines, _commentLines;

};