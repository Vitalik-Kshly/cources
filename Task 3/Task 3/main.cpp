#include "Scanner.h"
#include "ThreadInterface.h"

int main()
{

    ThreadInterface* thread = new ThreadInterface();
    thread->AddFile("files/1.cpp");
    thread->AddFile("files/2.cpp");
    thread->AddFile("files/3.cpp");
    thread->AddFile("files/4.cpp");
    thread->AddFile("files/5.cpp");
    thread->AddFile("files/6.cpp");
    thread->AddFile("files/7.cpp");
    thread->AddFile("files/7.cpp");
    thread->AddFile("files/7.cpp");
    thread->AddFile("files/7.cpp");
    thread->AddFile("files/7.cpp");
    thread->AddFile("files/7.cpp");
    thread->AddFile("files/7.cpp");

    thread->StartThread();
    return 0;
}