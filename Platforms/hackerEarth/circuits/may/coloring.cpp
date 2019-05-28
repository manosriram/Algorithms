#include <iostream>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;

ll ipow(ll base, ll exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}


int main() {
    ll n=0,k=0,res;

    cin >> n >> k;
    if (n == 2) 
            res = ipow(n,k);
        // res = pow(k,n);
    else res = k;

    cout << res % mod << '\n';
}