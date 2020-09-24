#include <iostream>
using namespace std;

int get2s(int n) {
    int ct = 0;
    while (n) {
        if (n % 10 == 2) ++ct;
        
        n /= 10;
    }
    return ct;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int mx = INT_MIN;
    for (int t=0;t<n;++t) {
        cin >> a[t];
        if (a[t] > mx) mx = a[t];
    }

    int res[100000];
    res[0] = 0;
    for (int t=1;t<=mx;++t) {
        res[t] = get2s(t) + res[t-1];
    }

    for (int t=0;t<n;++t) {
        cout << res[a[t]] << endl;
    }
}
