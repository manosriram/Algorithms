#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str1[40], str2[40], store[26];

    cout << "String 1 :";
    cin >> str1;
    cout << "String 2 :";
    cin >> str2;

    for (int t = 0; t < 26; t++)
        store[t] = 0;

    for (int t = 0; t < strlen(str1); t++)
    {
        store[str1[t] - 'a']++;
    }
    for (int t = 0; t < strlen(str2); t++)
    {
        store[str2[t] - 'a']++;
    }

    int count = 0;
    for (int t = 0; t < 26; t++)
    {
        if (store[t] == 1)
            count++;
    }
    cout << count << endl;
}