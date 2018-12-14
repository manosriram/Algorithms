#include <iostream>
using namespace std;

int main()
{
    long int res, T;
    unsigned long int a, b, k;
    unsigned long int t;
    cin >> T;

    while (T--)
    {
        res = 0;
        cin >> a >> b >> k;

        for (t = 0; t < k; t++)
        {
            if (t % 2 == 0)
            {
                res += a;
                continue;
            }
            else if (t % 2 != 0)
            {
                res -= b;
                continue;
            }
        }
        cout << res << '\n';
    }
}