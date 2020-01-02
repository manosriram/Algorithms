#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int t=0;t<n;++t) cin >> a[t];

    int sum = 0, max_ = INT_MIN;
    for (int t=0;t<n;++t) {
        sum += a[t];
        if (sum > max_) max_ = sum;
        if (sum < 0) sum = 0;
    }
    cout << max_ << endl;
}

