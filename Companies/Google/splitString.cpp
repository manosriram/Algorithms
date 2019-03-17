#include <iostream>
#include <string.h>
using namespace std;
char a[100];

bool checkPal(int k, int l)
{
    int count = 0;
    int i = k;
    int j = l;
    while (i < j)
    {
        if (a[i] != a[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main()
{
    string stringTemp[10];
    int ind = 0;
    string resSt;
    int n, tempCount = 0;
    cin >> a;

    n = strlen(a);
    int index = 0;
    for (int t = 0; t < n - 1; t++)
    {
        if (checkPal(index, t + 1))
        {
            cout << "Index : " << index << " endIndex : " << t + 1 << endl;
            tempCount++;
            index = t + 2;
            t++;
        }
    }

    tempCount > 1 ? cout << "Pal Found" << endl : cout << "No pal found." << endl;
}