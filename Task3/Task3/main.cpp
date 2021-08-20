#include "ThreadInterface.h"

int main(int argc, char *argv[])
{
    string path;
    if (argc == 1) 
    {
        cout << "StandartPath" << endl;
        path = string("files/small");
    }
    else
    {
        cout << argv[1];
        path = string(argv[1]);
    }
    cout << path << endl;
    ThreadInterface thread = ThreadInterface(path);
   
    thread.StartThread();

    return 0;
}
