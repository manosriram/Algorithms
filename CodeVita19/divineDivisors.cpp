#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#define trace(x) cerr << #x << " " << x << '\n';
#define ld long long
#define disp(n) for (auto t : n)
#define forn(t, n) for (ld t = 0; t < n; t++)
#define fornO(t, n) for (ld t = 2; t <= sqrt(n); t++)
#define pb push_back
#define mod 1000000007
#define c_sort(a) sort(a, a + sizeof(a) / sizeof(a[0]))
#define NL cout << '\n';
#define INF (int)1e9
using namespace std;
typedef vector<int> vI;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ld T, rnd;
    cin >> rnd;
    if (rnd > 0)
    {
        while (rnd--)
        {
            ld n;
            cin >> n;
            ld l = sqrt(n);
            ld a[l + 1];
            ld index = 0;

            for (int i = 1; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    if (n / i == i)
                        cout << i << " ";
                    else
                    {
                        cout << i << " ";

                        a[index] = n / i;
                        index++;
                    }
                }
            }
            for (int t = index - 1; t >= 0; t--)
                cout << a[t] << " ";
            NL;
        }
    }
    return 0;
}