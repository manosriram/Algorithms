#include <iostream>
#include <algorithm>
#include <math.h>
#define mod 1000000007
#define ll long long
using namespace std;

int main()
{
    ll n, k;
    ll rem = 0;
    cin >> n >> k;

    ll *a = new ll[n + 2];
    ll *b = new ll[n + 2];

    for (ll t = 1; t <= n; t++)
    {
        cin >> a[t];
        b[t] = a[t];
    }

    sort(a, a + n + 1);

    ll mid, sum = 0, ind;
    (n % 2 == 0) ? mid = n / 2 : mid = (n / 2) + 1;

    for (ll t = 1; t <= n; t++)
    {
        sum += abs(a[t] - a[mid]);
    }

    if (k != sum)
    {
        rem = sum - k;
    }
    else
    {
        rem = 0;
    }
    // rem = (k - sum) % mod;

    for (ll t = 1; t <= n; t++)
    {
        if (b[t] == (a[mid] + k))
        {
            a[mid] = b[t];
            ind = t;
            break;
        }
        if (a[mid] == b[t])
        {
            ind = t;
            break;
        }
    }

    ll res;
    // (k - sum > 0) ? res = sum - rem : res = sum - k;
    cout << ind << " " << rem << '\n';
}