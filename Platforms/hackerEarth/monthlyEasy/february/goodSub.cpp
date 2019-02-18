#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    unsigned int mod = 1000000007;
    unsigned int *hash = new unsigned int[26];
    unsigned long long int n, T, t, p;
    cin >> T;
    char *str = new char[10000];
    unsigned long long int prod, len;
    while (T--)
    {
        for (t = 0; t < 26; t++)
            hash[t] = 0;
        p = 0;
        prod = 1;
        cin >> str;
        len = strlen(str);
        while (len--)
        {
            hash[int(str[p] - 97)]++;
            p++;
        }
        for (t = 0; t < 26; t++)
        {
            if (hash[t] != 0)
            {
                prod *= hash[t];
                prod %= mod;
            }
        }
        cout << prod << endl;
    }
}