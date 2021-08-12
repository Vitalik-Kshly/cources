#include "Scanner.h"

int main()
{
    Scanner scanner("files/Types.cpp");
    // scanner.ScanFile();
    // scanner.ChangePath("files/file.cpp");
    scanner.ScanFile();
    scanner.PrintData();
    return 0;
}