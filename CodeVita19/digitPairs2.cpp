#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <iomanip>
#include <limits.h>
#define trace(x) cerr << #x << " " << x << '\n';
#define ld long long
#define disp(n) for (auto t : n)
#define forn(t, n) for (ld t = 0; t < n; t++)
#define pb push_back
#define mod 1000000007
#define c_sort(a) sort(a, a + sizeof(a) / sizeof(a[0]))
#define NL cout << '\n';
#define INF (int)1e9
using namespace std;
typedef vector<int> vI;
int max_, min_;

void displayBuckets(vI ob[], vI eb[])
{
    cout << "Odd Bucket" << endl;
    for (int k = 0; k < 10; k++)
    {
        cout << "Bucket " << k << " : ";
        disp(ob[k])
        {
            cout << t << " ";
        }
        NL;
    }
    NL;
    cout << "Even Bucket" << endl;
    for (int k = 0; k < 10; k++)
    {
        cout << "Bucket " << k << " : ";
        disp(eb[k])
        {
            cout << t << " ";
        }
        NL;
    }
    NL;
    return;
}

void selectGL(int n)
{
    while (n != 0)
    {
        int temp = (n % 10);
        if (temp > max_)
            max_ = (n % 10);
        if (temp < min_)
            min_ = (n % 10);

        n /= 10;
    }
    return;
}

int getSignificantBit(int n)
{
    // 102 -> 02
    int lnt = (n > 99) ? 3 : (n < 9) ? 1 : 2;

    if (lnt == 1)
    {
        return n;
    }
    else if (lnt == 2)
    {
        return (n / 10);
    }
    n /= 10;
    return (n / 10);
}

int removeSignificantBit(int n, int sig)
{
    // return (n - (sig * pow(10, lnt - 1)));

    int lnt = (n > 99) ? 3 : (n < 9) ? 1 : 2;
    if (lnt == 3)
    {
        n /= 10;
        if (n % 10 == 0)
            return 0;
    }
    else
        return n;
}

int main()
{
    int n = 01;
    std::setfill('0');
    cout
        << std::setw(2) << n << endl;
}