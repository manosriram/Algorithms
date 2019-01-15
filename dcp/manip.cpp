#include <iostream>
#include <string.h>
using namespace std;

bool checkSt(char s1[], char s2[])
{
    if (!strcmp(s1, s2))
        return 1;
    else
        return 0;
}

bool strManipulate(char s1[], char s2[])
{
    char temp;
    int t;
    temp = s1[0];
    for (int t1 = 0; t1 < strlen(s1); t1++)
    {
        for (t = 0; t < strlen(s1) - 1; t++)
        {
            s1[t] = s1[t + 1];
        }
        s1[strlen(s1) - 1] = temp;

        if (checkSt(s1, s2))
            return 1;
    }
    return 0;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    char *s1 = new char[n1];
    char *s2 = new char[n2];

    cin >> s1 >> s2;
    if (strManipulate(s1, s2))
        cout << "Match!" << endl;
    else
        cout << "Doesn't Match!" << endl;
}