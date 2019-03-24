#include <iostream>
#include <string.h>
#include <list>
#define ll long long int
using namespace std;

ll hashString(string s)
{
    ll hash = 0;
    for (int t = 0; t < s.length(); t++)
    {
        hash += s[t] - 'a';
    }
    return hash;
}

int main()
{
    int T;
    list<string> s[4];
    list<int> goals[4];
    list<string>::iterator i;

    // s.unique();
    string s1, s2, temp;
    int HG, AG;
    int hash1, hash2;
    // cin >> T;
    // while (T--)
    // {
    //     for (int t = 0; t < 2; t++)
    //     {
    //         cin >> s1 >> HG >> temp >> AG >> s2;
    //         hash1 = hashString(s1);
    //         hash2 = hashString(s2);
    //         s[hash1].push_back(s1);
    //         s[hash2].push_back(s2);
    //         goals[hash1].push_back(HG);
    //         goals[hash2].push_back(AG);
    //     }
    //     for (i = s[0].begin(); i != s[0].end(); i++)
    //         cout << *i << " ";
    //     // s.unique();
    // }
}