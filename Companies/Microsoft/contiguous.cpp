#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *a = new int[n];

        for (int t = 0; t < n; t++)
            cin >> a[t];

        int sum = 0, max = INT_MIN;
        for (int t = 0; t < n; t++)
        {
            sum += a[t];
            if (sum > max)
                max = sum;
        }
        cout << max << endl;
    }
}