#include <iostream>
#define ll long long int
using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll findGCD(ll arr[], ll n)
{
    ll result = arr[0];
    for (ll i = 1; i < n; i++)
        result = gcd(arr[i], result);

    return result;
}

int main()
{
    ll l, r, n, t;

    cin >> n >> l >> r;
    ll *a = new ll[n];

    ll maxMedian = ((l + r) / 2);
    for (t = 0; t < n; t++)
    {
        cin >> a[t];
        a[t] += maxMedian;
    }
    cout << findGCD(a, n) << '\n';
}