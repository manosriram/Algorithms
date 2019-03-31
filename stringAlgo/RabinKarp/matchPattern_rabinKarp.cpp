#include <iostream>
#include <math.h>
#include <string.h>
#define mod 1000000009
#define ll long long int
#define prime 3
using namespace std;

ll createHash(char str[], int n)
{
    ll res = 0;
    for (int t = 0; t < n; t++)
    {
        res += (ll)(str[t] * (ll)pow(prime, t));
    }
    return res;
}

ll reCalculateHash(char str[], int OI, int NI, ll OH, int patLength)
{
    ll newHash = OH - str[OI];
    newHash /= prime;
    newHash += (ll)(str[NI] * pow(prime, patLength - 1));
    return newHash;
}

bool checkEqual(char str1[], char str2[], int start1, int end1, int start2, int end2)
{
    if (end1 - start1 != end2 - start2)
    {
        return false;
    }
    while (start1 <= end1 && start2 <= end2)
    {
        if (str1[start1] != str2[start2])
        {
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}

int main()
{
    char s[100], pat[100];
    ll patHash, origHash;
    cout << "Orig String : ";
    cin >> s;
    cout << "Pattern : ";
    cin >> pat;

    patHash = createHash(pat, strlen(pat));
    origHash = createHash(s, strlen(pat));

    for (int t = 0; t < strlen(s) - strlen(pat) + 1; t++)
    {
        if (patHash == origHash && checkEqual(pat, s, t, (t + strlen(pat) - 1), 0, strlen(pat) - 1))
        {
            cout << t << '\n';
            break;
        }
        if (t < strlen(s) - strlen(pat))
        {
            origHash = reCalculateHash(s, t, t + strlen(pat), origHash, strlen(pat));
        }
    }
}