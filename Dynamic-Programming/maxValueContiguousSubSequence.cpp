#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n+1], dp[n+1]; 
    
    for (int t=0;t<n;t++) cin >> a[t];
    
    dp[0] = a[0];
    for (int t=0;t<n;++t) {
        if (dp[t-1] + a[t] > a[t])
            dp[t] = dp[t-1] + a[t];
        else
            dp[t] = a[t];

    }
    auto max_ = *max_element(dp, dp+n);

    cout << max_;
}

