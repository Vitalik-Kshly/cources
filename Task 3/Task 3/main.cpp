#include "Scanner.h"
#include "ThreadInterface.h"

int main()
{

    ThreadInterface* thread = new ThreadInterface("files/");
    thread->AddFile("files/1.cpp");
    thread->AddFile("files/5.cpp");
    thread->AddFile("files/5.cpp");
    thread->AddFile("files/5.cpp");
    thread->AddFile("files/5.cpp");
    thread->AddFile("files/5.cpp");
    thread->StartThread();
    return 0;
}