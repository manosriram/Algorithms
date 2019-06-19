#include <iostream>
#include <fstream>
#include <vector>
#include "helperFile.h"
using namespace std;

/*
    HelperFile
        - readData(string filePath) -> returns vector with read data.
        - writeData(string filePath, bool newLine, bool spacedAfter) -> returns bool
        - truncateFile(string filePath) -> void function.
        - removeFile(char filePath[]) -> returns bool

*/

int main()
{
    vector<string> vec;
    HelperFile helper;
    // vec = helper.readData("hello.txt");
    // helper.writeData("hello.txt", true, false);

    helper.truncateFile("hello.txt");
    if (!helper.removeFile("hello.txt"))
        cout << "Error Deleting file.." << endl;
}