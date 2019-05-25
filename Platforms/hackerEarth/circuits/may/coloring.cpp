#include <iostream>
#include <math.h>
#define ll long long
using namespace std;

int main() {
    ll n,k,res;

    cin >> n >> k;
    if (n == 2) res = pow(k,n);
    else res = k;

    cout << res << '\n';
}