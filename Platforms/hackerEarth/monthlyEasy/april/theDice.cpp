#include <iostream>
#include <string.h>
#define ll long long int
using namespace std;

int main()
{
    ll cnt = 0;
    char str[100000];
    bool first = false;
    cin >> str;
    ll len = strlen(str);
    ll last = len - 1;
    while (len--)
    {
        if (!first)
        {
            if (str[last] == '6')
            {
                cnt = -1;
                break;
            }
        }

        if (str[last] != '6')
            cnt++;

        last--;
        first = true;
    }
    cout << cnt << '\n';
}