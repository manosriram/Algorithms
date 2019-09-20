#include <iostream>
using namespace std;
int q;

int cutRod(int a[], int n)
{
    if (n == 1)
        return 0;

    q = INT_MIN;
    for (int t = 1; t < n; t++)
    {
        q = max(q, a[t] + cutRod(a, n - t));
    }
    return q;
}

int main()
{
    int a[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = sizeof(a) / sizeof(a[0]);
    int k;
    cin >> k;
    cout << cutRod(a, k) << endl;
}