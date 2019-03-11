#include <iostream>
using namespace std;

bool checkStatus(int a[], int n)
{
    int k;
    for (k = 1; k <= n; k++)
    {
        if (a[k] == k)
            continue;
        else
            break;
    }
    if (k == n)
        return true;
    else
        return false;
}

int main()
{
    int T, n, t;

    int *a = new int[n + 5];
    int *newA = new int[n + 5];

    cin >> T;
    while (T--)
    {
        int cnt = 0, flag = 0;
        cin >> n;
        for (t = 1; t <= n; t++)
        {
            cin >> a[t];
            newA[t] = a[t];
        }

        while (!checkStatus(a, n))
        {
            cnt++;

            for (t = 1; t <= n; t++)
            {
                a[t] = a[a[t]];
            }

            if (cnt == n)
            {
                flag = 1;
                cout << -1 << '\n';
                break;
            }
        }

        if (!flag)
        {
            cout << cnt << '\n';
        }
    }
}