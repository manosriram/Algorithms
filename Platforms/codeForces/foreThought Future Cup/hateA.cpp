#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string s1, s2;
    int ind1, ind2, t;

    cin >> s1;

    for (t = 0; t < s1.length(); t++)
    {
        if (s1[t] != 'a')
            s2 += s1[t];
    }

    ind1 = (s2.length() / 2) - 1; // bbcc
    bool bk = false;
    s2 = s2.substr(0, (s2.length() / 2));
    string from = s1.substr(s1.length() - s2.length(), s1.length());

    if (from == s2)
    {
        s1 = s1.substr(0, s1.length() - s2.length());
        cout << s1 << '\n';
    }
    else
        cout << ":(" << '\n';
}