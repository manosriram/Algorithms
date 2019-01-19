#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long int n, T, t, temp, sum;
    cin >> T;

    while (T--)
    {
        cin >> n;
        temp = (n * (pow(2, n - 1)));
        cout << temp % 1000000007 << '\n';
    }
}