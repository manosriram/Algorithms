#include <iostream>
#define nl cout << '\n';
using namespace std;

int main() {
    int a[30][30], c = 1;;
    int n = 4;
    for (int t=0;t<n;t++) {
        for (int j=0;j<n;j++) {
            a[t][j] = c;
            ++c;
        }
    }

    int fR = 0, fC = 0, lR = n-1, lC = n-1;
    int t;

    while (fC < lC) {
        for (t=fC;t<=lC;t++)
            cout << a[fR][t] << " ";

        ++fR;

        for (t=fR;t<=lR;t++)
            cout << a[t][lC] << " ";

        --lC;

        for (t=lC;t>=fC;--t)
            cout << a[lR][t] << " ";

        --lR;

        for (t=lR;t>=fR;--t)
            cout << a[t][fC] << " ";
        ++fC;
    }

}
