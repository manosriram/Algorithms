#include <iostream>
#define ll long long int
using namespace std;
#define ll long long int

bool findOdd(ll i, ll n)
{
    if (i % 2 != 0)
        return false;
    if (n <= 0)
        return true;

    return findOdd((n % 10), (n / 10));
}

ll incOdd(ll n, ll originalN)
{
    ll n1 = n;
    ll n2 = n1;
    ll check = 0;
    while (!check)
    {
        n = n1;
        ll i = n % 10;
        n /= 10;
        if (!findOdd(i, n))
        {
            n1++;
            continue;
        }
        else
        {
            check = 1;
        }
    }
    return (n1 - originalN);
}

ll decOdd(ll n, ll originalN)
{
    ll n1 = n;
    ll n2 = n1;
    ll check = 0;
    while (!check)
    {
        n = n1;
        ll i = n % 10;
        n /= 10;
        if (!findOdd(i, n))
        {
            n1--;
            continue;
        }
        else
        {
            check = 1;
        }
    }
    return (originalN - n1);
}

int main()
{
    ll n, T;
    cin >> T;
    ll p = T;
    while (T--)
    {
        cin >> n;
        ll y = incOdd(n, n);
        ll z = decOdd(n, n);
        (y < z) ? cout << "Case #" << (p - T) << " :" << y << '\n' : cout << "Case #" << (p - T) << " :" << z << '\n';
    }
}