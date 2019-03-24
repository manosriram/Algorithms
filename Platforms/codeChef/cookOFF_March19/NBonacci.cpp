#include <iostream>
#define ll long long int
#define mod 1000000009
using namespace std;

ll getXOR(ll ind, ll N, ll F[])
{
    ll val = 0;
    for (ll t = 1; t <= N; t++)
    {
        val ^= F[ind - t];
    }
    return val % mod;
}

ll getSK(ll ind, ll N, ll F[])
{
    ll val = 0;
    for (ll j = 1; j <= N; j++)
    {
        val ^= getXOR(j, N, F);
    }
    return val % mod;
}

int main()
{
    ll N, Q, query;
    cin >> N >> Q;
    ll *F = new ll[N + 1];
    for (ll j = 1; j <= N; j++)
        cin >> F[j];
    while (Q--)
    {
        cin >> query;
        cout << getSK(query, N, F) << '\n';
    }
}