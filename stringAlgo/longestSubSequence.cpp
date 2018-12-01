#include <iostream>
#include <string.h>
using namespace std;
int lcs[100][100];
int maximum;

int max(int a, int b)
{
    int u;
    if (a > b
            ? u = a
            : u = b)
        ;

    return u;
}

int subSeq(char str1[], char str2[], int len1, int len2, int i, int j)
{
    maximum = lcs[1][1];

    for (i = 1; i <= len1; i++)
    {
        for (j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                cout << str1[i - 1];
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            }

            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);

            if (maximum > lcs[i][j] ?: maximum = lcs[i][j])
                ;
        }
    }
    cout << maximum << endl;
}
int main()
{
    char one, two;
    char str1[100], str2[100];
    int n, i, j;

    cin >> str1 >> str2;
    int max;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 > len2 ? max = len1 : max = len2)
        ;

    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            lcs[i][j] = 0;
        }
    }
    subSeq(str1, str2, len1, len2, i, j);
}