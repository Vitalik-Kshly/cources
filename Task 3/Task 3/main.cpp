#include "Scanner.h"
#include "ThreadInterface.h"

int main()
{

    ThreadInterface thread = ThreadInterface("files/");
    
    thread.StartThread();

    return 0;
}
