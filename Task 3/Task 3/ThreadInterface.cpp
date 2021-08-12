#include "ThreadInterface.h"

ThreadInterface::ThreadInterface() :
	_threadsCount(7)
{
	time(&_start);
	_out.open("output.txt");
	_mainThread = make_shared<thread>(thread(&ThreadInterface::_threadProcessing, this));
	
	for (int i = 0; i < _threadsCount; i++)
	{
		shared_ptr<ThreadFile> temp(new ThreadFile);
		temp->Thread = make_shared<thread>(thread(&ThreadInterface::_fileScanner, this, temp));
		_threads.push_back(temp);
	}
	//_initThreads();
	//_mainThread.join();
}


//ThreadInterface::~ThreadInterface()
//{
//	_out.close();
//}

void ThreadInterface::AddFile(string ReadFilePath)
{
	_threadLock.lock();
	_processFiles.push_back(ReadFilePath);
	_threadLock.unlock();
}

void ThreadInterface::StartThread()
{
	_mainThread->join();
}

void* ThreadInterface::_threadProcessing()
{
	bool isEnd;
	cout << "Processing Thread!\n";
	while (true)
	{
 		if (!_processFiles.empty())
		{
			for (auto& thread : _threads)
			{
				if (!(*thread).IsActive)
				{
					_threadLock.lock();
					(*thread).FilePath = make_shared<string>(_processFiles.back());
					_processFiles.pop_back();
					(*thread).IsActive = true;
					_threadLock.unlock();
				}
			}
		}
		else
		{
			isEnd = true;
			for (auto Thread : _threads)
			{
				if (Thread->IsActive)
				{
					isEnd = false;
				}
			}
			if (isEnd)
			{
				time(&_end);
				_out << "Programm execution time is:" << difftime(_end, _start) << "sec.\n";
				_out.close();
				exit(0);
			}
		}
	}
}

void ThreadInterface::_initThreads()
{
	for (auto &Thread : _threads)
	{
		(*Thread).Thread->join();
	}
}

void ThreadInterface::_fileScanner(shared_ptr<ThreadFile> Thread)
{
	int _emptyLines, _codeLines, _commentLines, i = 0;
	time_t start, end;
	while (true)
	{
		if (Thread->IsActive)
		{
			time(&start);
			Scanner scanner(*Thread->FilePath);
			scanner.ScanFile();
			time(&end);
			scanner.GetData(_emptyLines, _codeLines, _commentLines);
			double dT = difftime(end, start);
			_threadLock.lock();
			_out << "FILE " << *Thread->FilePath << "\nTime is: " << dT << " sec:" << endl;
			_out << "Empty lines" << ": " << _emptyLines << endl;
			_out << "Code lines" << ": " << _codeLines << endl;
			_out << "Comment lines" << ": " << _commentLines << "\n";
			_out << "Count: " << _commentLines + _codeLines + _emptyLines << "\n\n";
			Thread->IsActive = false;
			_threadLock.unlock();
			
		}
	}
}