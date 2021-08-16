#pragma once
#include <vector>
#include <thread>
#include <time.h>
#include <mutex>
#include <fstream>
#include <memory>
#include <filesystem>

#include "Scanner.h"

namespace fs = std::filesystem;
struct ThreadFile
{
	shared_ptr<thread> Thread;
	shared_ptr<string> FilePath;
	bool IsActive;

	ThreadFile()
	{
		IsActive = false;
		FilePath = nullptr;
		Thread = nullptr;
	}
};

class ThreadInterface
{
public:
	ThreadInterface(string dir);
	~ThreadInterface();
	void AddFile(string ReadFilePath);
	void StartThread();

private:
	bool _isEnd;
	shared_ptr<thread> _mainThread;
	shared_ptr<thread> _scanThread;
	const int _threadsCount;
	void _threadProcessing();
	void _fileScanner(shared_ptr<ThreadFile>);
	void _getFiles();
	fs::recursive_directory_iterator _iterFileStream;
	vector<shared_ptr<ThreadFile>> _threads;
	vector<string> _processFiles;
	vector<string> _fileExtensions;
	mutex _threadLock;
	ofstream _out;
	time_t _start, _end;
	string _dir;
};
