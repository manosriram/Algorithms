#include <iostream>
#include <math.h>
#define ll long long
using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;

    ll xi[2000000], yi[2000000], xB[2000000], yB[2000000];

    for (ll t = 0; t < n; t++)
        cin >> xi[t] >> yi[t];

    for (ll t = 0; t < m; t++)
        cin >> xB[t] >> yB[t];

    ll guards = 0, prevT = -1, IEguards = 0;
    for (ll t = 0; t < n; t++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (abs(yi[t] - yB[j]) <= xB[j] - xi[t])
            {
                if (prevT == j)
                    IEguards++;

                prevT = j;
                guards++;
            }
            else
                continue;
        }
    }

    cout << IEguards << '\n';
}