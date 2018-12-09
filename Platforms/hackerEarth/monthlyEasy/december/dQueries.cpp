#include <iostream>
using namespace std;

int main()
{
    long int n, q;

    cin >> n >> q;
    int *a = new int[n];
    int t;
    int type, L, R, X;

    for (t = 0; t < n; t++)
        cin >> a[t];

    while (q--)
    {
        cin >> type >> L >> R >> X;

        if (type == 1)
        {
            for (t = L - 1; t < R; t++)
                a[t] += X;
        }
        if (type == 2)
        {
            for (t = L - 1; t < R; t++)
                a[t] = X;
        }
    }

    for (t = 0; t < n; t++)
        cout << a[t] << " ";
}