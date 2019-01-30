#include <iostream>
using namespace std;

int main()
{
    int wordCount = 0, ind = 0, t;
    char temp;
    char storeWord[30], storeChar[30];
    int store[30];

    cin >> storeWord;
    for (t = 0; t < strlen(storeWord); t++)
    {
        if (storeWord[t] == storeWord[t + 1])
        {
            wordCount++;
            continue;
        }
        else
        {
            wordCount++;
            store[ind] = wordCount;
            storeChar[ind] = storeWord[t];
            wordCount = 0;
            ind++;
        }
    }
    for (t = 0; t < ind; t++)
    {
        cout << storeChar[t] << store[t];
    }
    cout << endl;
}