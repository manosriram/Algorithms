#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    freopen("in.txt", "r", stdin);
    cin >> n;
    int a[n+1][n+1], dp[n+1][n+1];

    for (int t=0;t<n;t++) {
        for (int j=0;j<n;++j) {
            cin >> a[t][j];
        }
    }

    dp[0][0] = 0;
    for (int t=1;t<n;t++) {
        if (abs(a[0][t] - a[0][t-1]) == 1)
            dp[0][t] = dp[0][t-1] + 1;
        else dp[0][t] = 0;
        
        if (abs(a[t][0] - a[t-1][0]) == 1)
            dp[t][0] = dp[t-1][0] + 1;
        else
            dp[t][0] = 0;
    }
    int max_ = INT_MIN;
    for (int i=1;i<n;++i) {
        for (int j=1;j<n;++j) {
          if (abs(a[i][j] - a[i][j-1]) == 1)
            dp[i][j] = dp[i][j-1] + 1;
            
          if (abs(a[i][j] - a[i-1][j]) == 1 && dp[i-1][j] > dp[i][j-1])
            dp[i][j] = dp[i-1][j] + 1;

          if (abs(a[i][j] - a[i][j-1]) != 1 && abs(a[i][j] - a[i-1][j]) != 1)
            dp[i][j] = 0;  

          if (dp[i][j] > max_)
              max_ = dp[i][j];
        }
    }
    cout << max_;
}

