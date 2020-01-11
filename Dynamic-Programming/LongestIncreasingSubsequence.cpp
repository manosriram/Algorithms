#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[n], dp[n];

    for (int t=0;t<n;t++) {
        cin >> a[t];
        dp[t] = 1;
    }

    for (int i=1;i<n;++i) {
        for (int j=0;j<i;++j) {
            if (a[j] < a[i] && dp[i] <= dp[j])
                dp[i] = dp[j] + 1;
        }
    }
    auto max_ = *max_element(dp, dp+n);

    cout << max_;
}

