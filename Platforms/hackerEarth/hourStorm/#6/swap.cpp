#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int T;
    int n, i, j;
    cin >> T;

    while (T--)
    {
        cin >> n;

        char *s1 = new char[n];
        char *s2 = new char[n];

        cin >> s1;
        cin >> s2;
        int flag = 0;
        char temp;
        for (i = 0; i < n; i++)
        {
            if (!flag)
            {
                for (j = n - 1; j >= 0; j--)
                {
                    if (!flag)
                    {
                        temp = s1[i];
                        s1[i] = s2[j];
                        s2[j] = temp;

                        if (!strcmp(s1, s2))
                        {
                            flag = 1;
                            cout << "YES" << endl;
                        }
                        else
                            continue;
                    }
                }
            }
            else
                break;
        }
        if (!flag)
            cout << "NO" << endl;
    }
}