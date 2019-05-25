#include <iostream>
#include <string>
using namespace std;

int distDP(int i, int j, string s1, string s2)
{
    if (i == s1.length() || j == s2.length())
        return 0;

    else if (s1[i] != s2[j])
        return 1 + distDP(i + 1, j + 1, s1, s2);

    else
        return distDP(i + 1, j, s1, s2);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << distDP(0, 0, s1, s2) << endl;
}