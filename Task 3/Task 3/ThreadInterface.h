#pragma once
#include <vector>
#include <thread>
#include <time.h>
#include <mutex>
#include <fstream>
#include "Scanner.h"
#include <memory>

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
	ThreadInterface();
	//~ThreadInterface();
	void AddFile(string ReadFilePath);
	void StartThread();
	


private:
	shared_ptr<thread> _mainThread;
	const int _threadsCount;
	void* _threadProcessing();
	void _fileScanner(shared_ptr<ThreadFile>);
	void _initThreads();
	vector<shared_ptr<ThreadFile>> _threads;
	//vector<ThreadFile> _inactiveThreads;
	vector<string> _processFiles;
	mutex _threadLock;
	ofstream _out;
	time_t _start, _end;
};
