#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <string>
#define max INT_MAX - 10
using namespace std;
ifstream fileReader;
ofstream fileWriter;
vector<string> vec;

class HelperFile
{
public:
    vector<string> readData(string filePath)
    {
        char *arr = new char[max];
        fileReader.open(filePath);
        // fileReader.getline(arr, max, std::ios::app);

        while (fileReader.is_open()) {
            string line;
            while (getline(fileReader, line)) {
                vec.push_back(line.c_str());
            }
            fileReader.close();
        }
        vec.push_back(arr);
        return vec;
    }

    bool writeData(string filePath, bool newLine, bool spacedAfter) {
        char *arr = new char[max];

        cin.getline(arr, max);
        fileWriter.open(filePath, std::ios::app);

        if (newLine)
            fileWriter << '\n' << arr;
        else if (spacedAfter)
            fileWriter << " " << arr;
        else
            fileWriter << arr;
            
        if (!fileWriter.is_open()) return false;
        
        return true;
    }

    void truncateFile(string filePath) {
        fileWriter.open(filePath);
        fileWriter << "";
        fileWriter.close();
        return;
    }

    int removeFile(char filePath[]) {
        return remove(filePath);
    }

};