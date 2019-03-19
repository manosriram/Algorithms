#include <iostream>
using namespace std;

int main()
{
    int sum = 0, maxEnd, n, t;
    cin >> n;
    int *a = new int[n];

    for (t = 0; t < n; t++)
        cin >> a[t];

    maxEnd = a[0];
    for (t = 0; t < n; t++)
    {
        sum += a[t];

        if (maxEnd < sum)
            maxEnd = sum;
        if (sum < 0)
            sum = 0;
    }

    cout << sum << endl;
}