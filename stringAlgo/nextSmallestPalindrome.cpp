#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;

ll getCount(ll num)
{
    ll cnt = 0;
    while (num > 0)
    {
        cnt++;
        num /= 10;
    }
    return cnt;
}

ll nextSmallestPalindrome(ll number)
{
    ll dup = number;
    ll length = getCount(number);
    if (length % 2 == 0)
    {
        ll left = length / 2;
        ll right = (length / 2) + 1;

        while (left--)
        {
            dup /= 10;
        }
        left = dup % 10;
        dup = number;
        while (right--)
        {
            dup /= 10;
        }
        right = dup % 10;
        dup /= 10;
        if (left > right)
        {
            ll temp;
            for (int t = 0; t < length / 2; t++)
            {
                temp += (dup % 10) * pow(10, (length / 2 - t - 1));
            }
        }
    }
}

int main()
{
    ll number;
    cin >> number;
}