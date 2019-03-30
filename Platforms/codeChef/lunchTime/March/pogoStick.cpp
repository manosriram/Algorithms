#include <iostream>
using namespace std;

int main()
{
    int T;
    int N, K;

    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        int *a = new int[N];
        int sum = 0, max = INT_MIN;

        for (int t = 0; t < N; t++)
            cin >> a[t];

        for (int t = 0; t < N; t++)
        {
            for (int j = t; j < N; j++)
            {
                sum += a[j];
                j += K - 1;
            }
            if (sum > max)
                max = sum;
            sum = 0;
        }

        cout << max << '\n';
    }
}