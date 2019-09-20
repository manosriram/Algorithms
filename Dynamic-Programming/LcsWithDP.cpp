#include <iostream>
using namespace std;
int LCS[100][100];

int findMax(int a, int b)
{
    return a > b ? a : b;
}

int LcsWithDP(int i, int j, string s1, string s2)
{
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            else
                LCS[i][j] = findMax(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    return LCS[s1.length()][s2.length()];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << LcsWithDP(0, 0, s1, s2) << '\n';
}