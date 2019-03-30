#include <iostream>
#define ll long long int
using namespace std;

ll store[70];

ll fibo(ll n)
{
    if (n <= 1)
        return n;

    if (store[n] != -1)
        return store[n];

    store[n] = fibo(n - 1) + fibo(n - 2);

    return store[n];
}

int main()
{
    ll n;
    cin >> n;
    for (ll t = 0; t < 70; t++)
    {
        store[t] = -1;
    }
    cout << fibo(n) << endl;
}