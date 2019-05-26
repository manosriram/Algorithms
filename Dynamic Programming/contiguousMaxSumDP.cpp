#include <iostream>
using namespace std;

int findMax(int a, int b)
{
    return (a > b) ? a : b;
}

int maxContiguousSum(int a[], int n)
{
    int currentHigh = a[0], t, allTimeHigh = INT_MIN;

    for (t = 1; t <= n; t++)
    {
        currentHigh = findMax((a[t - 1] + a[t]), a[t]);

        if (currentHigh > allTimeHigh)
            allTimeHigh = currentHigh;
    }
    return allTimeHigh;
}

int main()
{
    int n, sum = 0;
    cin >> n;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int res = maxContiguousSum(a, n);

    cout << res << endl;
}