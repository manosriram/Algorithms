#include <iostream>
#include <math.h>
#define ll long long
using namespace std;

ll xi[2000000], yi[2000000], xB[2000000], yB[2000000];
int countGuards(int t, int j, int n, int m)
{
    static int prevV = -1, IEguards;
    if (t == n - 1 && j == m - 1)
        return IEguards;

    if (j == m - 1)
    {
        j = 0;
        t++;
    }

    if (abs(yi[t] - yB[j]) <= xB[j] - xi[t])
    {
        if (prevV == j)
            IEguards++;

        prevV = j;
    }
    return countGuards(t, j + 1, n, m);
}

int main()
{
    ll n, m;
    cin >> n >> m;

    for (ll t = 0; t < n; t++)
        cin >> xi[t] >> yi[t];

    for (ll t = 0; t < m; t++)
        cin >> xB[t] >> yB[t];

    // ll prevV = -1, IEguards = 0;
    // for (ll t = 0; t < n; t++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         if (abs(yi[t] - yB[j]) <= xB[j] - xi[t])
    //         {
    //             cout << "i : " << t << " "
    //                  << "j : " << j << endl;
    //             if (prevV == j)
    //                 IEguards++;

    //             prevV = j;
    //         }
    //         else
    //             continue;
    //     }
    // }

    cout << countGuards(0, 0, n, m) << '\n';
}