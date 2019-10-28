#include <math.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "unordered_map"
#define trace(x) cerr << #x << " " << x << '\n';
#define ld long long
#define disp(n) for (auto t : n)
#define forn(t, n) for (ld t = 0; t < n; t++)
#define pb push_back
#define mod 1000000007
#define c_sort(a) sort(a, a + sizeof(a) / sizeof(a[0]))
#define NL cout << '\n';
#define INF (int)1e9
#define sws cin.sync_with_stdio(false);
#define tieNULL cin.tie(NULL);
using namespace std;
typedef vector<int> vi;

int main() {
    ld T;
    
    freopen("IN.txt", "r", stdin);

    cin >> T;
    unordered_map<int, int> u;
    ld n, m, q, temp;
    ld lp = 1;
    
    while (T--) {
        cin >> n >> m >> q;
        ld mult[q];
        for (ld t = 0; t < m; t++) {
            cin >> temp;
            u[temp] = temp;
        }
        ld mt;
        ld sum = 0;
        for (ld t = 0; t < q; t++) {
            cin >> mt;
            if (mt == 1) {
                sum = n - m;
                continue;
            }
            for (ld t1 = mt; t1 <= n; t1 += mt) {
                if (!u[t1] && (t1 == mt || (t1 % mt == 0)))
                    ++sum;
            }
        }
        cout << "Case #" << lp << " " << sum << '\n';
        ++lp;
    }
}