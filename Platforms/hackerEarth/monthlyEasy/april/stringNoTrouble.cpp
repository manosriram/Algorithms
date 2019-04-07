#include <iostream>
#include <string.h>
#define ll long long int
using namespace std;

int main()
{
    char str[2000000];
    ll count = 0;
    cin >> str;
    ll max = -2147483648;
    for (ll t = 0; t < strlen(str) - 1; t++)
    {
        if (str[t] != str[t + 1])
            count++;
        else
            count = 0;

        if (count > max)
            max = count;
    }
    cout << count + 1 << endl;
    cout << max + 1 << '\n';
}