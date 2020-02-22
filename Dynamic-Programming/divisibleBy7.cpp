#include <iostream>
#include <map>
using namespace std;

int main() {
    int a[] = {3, 11, 4, 7, 14}, s = 0;
    int K = 7;
    int n = sizeof(a) / sizeof(a[0]);
    map<int, int> mp;    

    for (int t=0;t<n;++t) mp[a[t] % K]++;
    
    s = mp[0] * (mp[0] - 1) / 2;    

    for (int t=1;t<=K/2 && t != (K - t);++t)
        s += mp[t] * mp[K - t];

    if (!(K & 1))
        s += (mp[K/2] * (mp[K / 2] - 1) / 2);

    cout << s;

}
