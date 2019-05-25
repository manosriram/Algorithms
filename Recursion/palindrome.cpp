#include <iostream>
#include <string.h>
using namespace std;

bool pal(int i, int j, char str[])
{
    if (i == j)
        return 1;

    if (str[i] == str[j])
    {
        return pal(i + 1, j - 1, str);
    }
    else
        return 0;
}

int main()
{
    char str[30];
    cin >> str;
    if (pal(0, (strlen(str) - 1), str))
    {
        cout << "Palindrome!" << endl;
    }
    else
        cout << "Not a Palindrome!" << endl;
}