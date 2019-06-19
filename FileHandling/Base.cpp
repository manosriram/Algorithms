#include <iostream>
#include <fstream>
#include <vector>
#include "helperFile.h"
using namespace std;

/*
    HelperFile
        - readData(string filePath) -> returns vector with read data (line by line).
        - writeData(string filePath, bool newLine, bool spacedAfter) -> returns bool
        - truncateFile(string filePath) -> void function.
        - removeFile(char filePath[]) -> returns bool

*/

int main()
{
    vector<string> vec;
    HelperFile helper;
    vec = helper.readData("hello.txt");
    // helper.writeData("hello.txt", true, false);

}