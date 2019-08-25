#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <tuple>
#include <set> 
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

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    ld n, cnt = 0, T;

    set< tuple<int, int, int> > st;
    tuple <int, int, int> temp;

    cin >> T;
    while (T--) {
    cin >> n;
    	
    for (ld t=1;t<n-1;t++) {
    	for (ld j=1;j<n-1;j++) {
    		for (ld k = 1;k<n-1;k++) {
    			if (t + j + k == n)  {
    				temp = make_tuple(t,j,k);
    				if (std::find(st.begin(), st.end(), temp) == st.end()) {
    					st.insert(make_tuple(t,j,k));
    				}
    			}
    		}
    	}	
    }

    cout << st.size() << endl;
}
    return 0;
}
