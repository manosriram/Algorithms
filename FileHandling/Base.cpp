#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream myFile;
    ifstream fileReader;
    char arr[100];

    myFile.open("hello.txt", std::ios::app);

    cin.getline(arr, 100);

    myFile << "\n"
           << arr;
    myFile.close();

    fileReader.open("hello.txt");

    fileReader.getline(arr, 100, std::ios::app);
    cout << arr << endl;
}