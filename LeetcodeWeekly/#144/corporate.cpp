#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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
using namespace std;
typedef vector<int> vI;

vector<int> corpFlightBookings(vector< vector<int> > bookings, int n)
{
    unordered_map<int, int> ump;
    vector<int> v;
    
    forn(t, bookings.size())
    {
        int st = bookings[t][0];
        int ed = bookings[t][1];
        for (int t1=st;t1<=ed;t1++) {
            ump[t1] += bookings[t][2];
        }
    }
    
    for (auto t=ump.begin();t!=ump.end();t++) {
        v.push_back(t->second);
    }
    reverse(v.begin() + 1, v.end());
    return v;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ld T, r, c;
    vector<int> row1 = {1, 2, 10};
    vector<int> row2 = {2, 3, 20};
    vector<int> row3 = {2, 5, 25};
    vector< vector<int> > vc;
    vc.push_back(row1);
    vc.push_back(row2);
    vc.push_back(row3);

    vector<int> v2 = corpFlightBookings(vc, 5);
    for (auto itr = v2.begin();itr != v2.end(); itr++) {
        cout << *itr << " ";
    }
    return 0;
}