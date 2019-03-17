#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int hashFunction(char a[], int stInd, int endIn)
{
    int count = (endIn - stInd), hash = 0;
    for (int t = stInd; t < endIn; t++)
    {
        cout << count << '\n';
        hash += (int(a[t]) - 97) * pow(10, count - 1);
        count--;
        cout << " hash : " << hash << endl;
    }
    return (hash % 1000000009);
}

int main()
{
    char a[100], pattern[100];
    cin >> pattern;

    cout << hashFunction(pattern, 0, strlen(pattern)) << endl;
}