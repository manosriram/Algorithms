#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n;

    int *a = new int[n];
    int *res = new int[n];

    for (t = 0; t < n; t++)
        cin >> a[t];

    int flag;

    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                flag = 1;
                res[i] = a[j];
                break;
            }
        }
        if (!flag)
        {
            res[i] = -1;
        }
    }

    for (t = 0; t < n; t++)
        cout << res[t] << " ";
}