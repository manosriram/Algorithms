#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];

    int t;
    for (t=0;t<n;t++)
    cin >> a[t];

    int i,j;
    int v;
    for (t=1;t<n;t++) {
        v = a[t];
        j=t;
        while(a[j-1] > v && j>=1) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }

    for (t=0;t<n;t++)
    cout << a[t] << " ";
}