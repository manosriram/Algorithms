#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string a;
    cin >> a;
    int count = 0;
    int len = a.length();
    while (len >= 0)
    {
        if (a[len] == 'a')
            count++;

        len--;
    }
    len = a.length();
    bool flag = false;

    while (count <= (len / 2))
    {
        len--;
    }

    // if (count > (a.length() / 2))
    //     cout << a.length() << '\n';
    // else
    //     cout << (a.length() / count) << '\n';
    cout << len << '\n';
}