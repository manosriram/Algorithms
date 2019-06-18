#include <iostream>
using namespace std;
// static int sum, temp;

int rob(int a[], int n, int index, int sum)
{
    if (index >= n)
        return sum;

    // sum += a[index];
    return rob(a, n, index + 2, sum += a[index]);
    // return sum;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];

    for (int t = 0; t < n; t++)
        cin >> a[t];

    int res = max(rob(a, n, 0, 0), rob(a, n, 1, 0));

    res > (a[0] + a[n - 1]) ? cout << res << '\n' : cout << (a[0] + a[n - 1]) << '\n';
}