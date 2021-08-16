#include "ThreadInterface.h"

ThreadInterface::ThreadInterface(string dir) :
    _threadsCount(5),
    _dir(dir),
    _iterFileStream(dir),
    _isEnd(false),
    _fileExtensions{".cpp", ".h", ".c", ".hpp"}
{
    time(&_start);
    _out.open("output.txt");
    _mainThread = make_shared<thread>(thread(&ThreadInterface::_threadProcessing, this));
    _scanThread = make_shared<thread>(thread(&ThreadInterface::_getFiles, this));
    
    for (int i = 0; i < _threadsCount; i++)
    {
        shared_ptr<ThreadFile> temp(new ThreadFile);
        temp->Thread = make_shared<thread>(thread(&ThreadInterface::_fileScanner, this, temp));
        _threads.push_back(temp);
    }
}

ThreadInterface::~ThreadInterface()
{
    time(&_end);
    _out << "Programm execution time is:" << difftime(_end, _start) << "sec.\n";
    _out.close();

    for (auto& thread : _threads)
    {
        thread->Thread->detach();
    }
}

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

void ThreadInterface::_threadProcessing()
{
    _scanThread->join();
    bool isEnd = false;
    cout << "Processing Thread!\n";
    
    while (!_isEnd)
    {
        if (!_processFiles.empty())
        {
            for (auto& thread : _threads)
            {
                if (!thread->IsActive && !_processFiles.empty())
                {
                    _threadLock.lock();
                    thread->FilePath.reset();
                    thread->FilePath = make_shared<string>(_processFiles.back());
                    _processFiles.pop_back();
                    thread->IsActive = true;
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
                _threadLock.lock();
                _isEnd = true;
                _threadLock.unlock();
            }
        }
    }
}

void ThreadInterface::_getFiles()
{
    
    while (!(_iterFileStream == end(_iterFileStream)))
    {
        auto path = _iterFileStream->path();
        string extension = path.extension().string();
        string file = path.string();

        if (find(_fileExtensions.begin(), _fileExtensions.end(), extension) != _fileExtensions.end())
        {
            _threadLock.lock();
            _processFiles.push_back(file);
            _threadLock.unlock();
        }
        _iterFileStream++;
    }
}

void ThreadInterface::_fileScanner(shared_ptr<ThreadFile> Thread)
{
    int _emptyLines, _codeLines, _commentLines;
    time_t start, end;
    double dTime;
    while (!_isEnd)
    {
        if (Thread->IsActive)
        {
            time(&start);
            cout << "Scanning: " << *Thread->FilePath << endl;
            Scanner scanner(*Thread->FilePath);
            scanner.ScanFile();
            scanner.GetData(_emptyLines, _codeLines, _commentLines);
            time(&end);
            dTime = difftime(end, start);
            _threadLock.lock();
            _out << "FILE " << *Thread->FilePath << "\nTime is: " << dTime << " sec:" << endl;
            _out << "Empty lines" << ": " << _emptyLines << endl;
            _out << "Code lines" << ": " << _codeLines << endl;
            _out << "Comment lines" << ": " << _commentLines << "\n";
            _out << "Count: " << _commentLines + _codeLines + _emptyLines << "\n\n";
            Thread->IsActive = false;
            _threadLock.unlock();
            
        }
    }
}