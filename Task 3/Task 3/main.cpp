#include "Scanner.h"
#include "ThreadInterface.h"

int main()
{

    ThreadInterface* thread = new ThreadInterface("files/");
    
    thread->StartThread();
 
    return 0;
}
