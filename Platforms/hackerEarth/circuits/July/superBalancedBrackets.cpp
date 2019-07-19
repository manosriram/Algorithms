#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#define trace(x) cerr << #x << " " << x << '\n';
#define ld long long
#define disp(n) for (auto t : n)
#define forn(t, n) for (ld t = 0; t < n; t++)
#define forRange(t, n, start) for (ld t = start; t < n; t++)
#define pb push_back
#define mod 1000000007
#define c_sort(a) sort(a, a + sizeof(a) / sizeof(a[0]))
#define NL cout << '\n';
#define INF (int)1e9
using namespace std;
typedef vector<int> vI;

int superBB(string bk)
{
    if (!bk.length() || bk[0] != '(')
        return 0;

    int cnt = 0;

    int mid = bk.length() / 2;

    forRange(t, bk.length(), mid)
    {
        if (bk[t] == ')')
            cnt++;
    }
    return cnt * 2;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ld T;

    cin >> T;
    string bk;
    while (T--)
    {
        cin >> bk;
        cout << superBB(bk) << endl;
    }

    return 0;
}