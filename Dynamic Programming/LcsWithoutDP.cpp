#include <iostream>
using namespace std;

int findMax(int a, int b)
{
    return a > b ? a : b;
}

int findLCS(int i, int j, string s1, string s2)
{
    if (i == s1.length() || j == s2.length())
        return 0;

    else if (s1[i] == s2[j])
        return 1 + findLCS(i + 1, j + 1, s1, s2);

    else
        return findMax(findLCS(i + 1, j, s1, s2), findLCS(i, j + 1, s1, s2));
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << findLCS(0, 0, s1, s2) << '\n';
}