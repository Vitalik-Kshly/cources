#include "ThreadInterface.h"

const vector<string> ThreadInterface::_fileExtensions = { ".cpp", ".h", ".c", ".hpp" };

ThreadInterface::ThreadInterface(string dir) :
    _threadsCount(THREADS_COUNT),
    _dir(dir),
    _iterFileStream(dir) 
{
    _allCommentLines = _allEmptyLines = _allCodeLines = _allLines = _allFiles = _filesScanned = 0;
    _startClock = clock();
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

void ThreadInterface::_printFinalStats()
{
    _out << "All code lines: " << _allCodeLines << endl
        << "All comment lines: " << _allCommentLines << endl
        << "All lines: " << _allLines << endl
        << "Count of detected files: " << _allFiles << endl
        << "Count of scanned files: " << _filesScanned << endl
        << "Programm execution time is: " << difftime(_endClock, _startClock) / CLK_TCK << " sec.\n";
    _out.close();
}

ThreadInterface::~ThreadInterface()
{
    _endClock = clock();
    _printFinalStats();
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
    bool allThredsFinished = false;
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
            allThredsFinished = true;
            for (auto Thread : _threads)
            {
                if (Thread->IsActive)
                {
                    allThredsFinished = false;
                }
            }
            if (allThredsFinished)
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
        _allFiles += 1;
        if (find(_fileExtensions.begin(), _fileExtensions.end(), extension) != _fileExtensions.end())
        {
            _filesScanned += 1;
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
    clock_t startClock, endClock;
    double dTime;
    while (!_isEnd)
    {
        if (Thread->IsActive)
        {
            startClock = clock();
            cout << "Scanning: " << *Thread->FilePath << endl;
            Scanner scanner(*Thread->FilePath);
            scanner.ScanFile();
            scanner.GetData(_emptyLines, _codeLines, _commentLines);
            _allLines += _codeLines + _commentLines;
            _allCodeLines += _codeLines;
            _allCommentLines += _commentLines;
            endClock = clock();
            dTime = difftime(endClock, startClock) / CLK_TCK;
            _threadLock.lock();
            _out << "FILE " << *Thread->FilePath << "\nTime is: " << dTime << " sec:" << endl
                << "Empty lines" << ": " << _emptyLines << endl
                << "Code lines" << ": " << _codeLines << endl
                << "Comment lines" << ": " << _commentLines << "\n\n";
            Thread->IsActive = false;
            _threadLock.unlock();
        }
    }
}