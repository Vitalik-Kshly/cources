#include "Scanner.h"

Scanner::Scanner(string path)
{
	_codeLines = _commentLines = _emptyLines = 0;
	ChangePath(path);
	_out.open("output.cpp");
}

void Scanner::ChangePath(string path)
{
	if (_fileStream.is_open())
	{
		_fileStream.close();
	}
	_filePath = path;
	_fileStream.open(path);
}


void Scanner::ScanFile()
{
	size_t IndexOfCode, IndexOfInlineComment, IndexOfComment, IndexOfCloseComment = string::npos;
	bool inCommentBlock = false;
	string line;

	while (getline(_fileStream, line))
	{
		IndexOfCode = line.find_first_not_of(' ');
		IndexOfInlineComment = line.find("//");
		IndexOfComment = line.find("/*");
		
		if (line.empty() || IndexOfCode == string::npos)
		{
			_emptyLines += 1;
			_printLine(line);

		}
		else if (IndexOfComment != string::npos && IndexOfInlineComment > IndexOfComment)
		{
			_commentLines += 1;
			inCommentBlock = true;
			_codeLines += _lineContainsCode(line);
			_printLine(line);
			while (inCommentBlock && getline(_fileStream, line))
			{
				IndexOfCode = line.find_first_not_of(' ');
				if (line.empty() || IndexOfCode == string::npos)
				{
					_emptyLines += 1;
					continue;
				}
				_commentLines += 1;
				IndexOfCloseComment = (line.rfind("*/"));
				if (IndexOfCloseComment != string::npos)
				{
					inCommentBlock = false;
				}
				_codeLines += _lineContainsCode(line, inCommentBlock);
				_printLine(line);
			}
		}
		else if (IndexOfInlineComment != string::npos)
		{
			_commentLines += 1;
			_printLine(line);
		}
		else
		{
			_codeLines += _lineContainsCode(line);
			_printLine(line);
		}
	}
}

Scanner::~Scanner()
{
	_out.close();
	_fileStream.close();
}

void Scanner::_printLine(string line)
{
	_out << "Empty :" << _emptyLines << "Code :" << _codeLines << "Comments :" << _commentLines << endl;
	_out << line << endl;
}

bool Scanner::_lineContainsCode(string line, bool inCommentBlock)
{
	size_t IndexOfCode = line.find_first_not_of(' ');
	size_t IndexOfInlineComment = line.find("//");
	size_t IndexOfComment = line.find("/*");
	size_t IndexOfCloseComment = line.rfind("*/");
	if (IndexOfCode == IndexOfInlineComment || inCommentBlock)
	{
		return false;
	}
	if (IndexOfCloseComment != string::npos)
	{
		if (line.find_first_not_of(' ', IndexOfCloseComment + 2) == string::npos)
		{
			return false;
		}
	}
	if (IndexOfCode < IndexOfInlineComment && IndexOfCode < IndexOfComment)
	{
		return true;
	}


	return 0;
}

void Scanner::PrintData() 
{
	_printLine();
}
