#include <iostream>
using namespace std;

int countMinimumCost(int a[], int n, int index)
{
    int sum = 0, ind = index;

    for (int t = ind; t < n; t++)
    {
        if (t == n - 1)
            sum += a[t];
        else
            sum += min(a[t], a[t + 1]);

        if (a[t] <= a[t + 1])
            t++;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];

    for (int t = 0; t < n; t++)
        cin >> a[t];

    int res = min(countMinimumCost(a, n, 0), countMinimumCost(a, n, 1));
    cout << res << endl;
}