#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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
    int T, N, M, j, i;
    cin >> T;
    while (T--) {
    	int temp;
    	cin >> N >> M;
    	int A[N + 1], B[M + 1];
    	for (int t=1;t<=N;t++) {
    		cin >> A[t];
    		// scanf("%d", &A[t]);
    	}
    	for (int t=1;t<=M;t++) {
    		cin >> B[t];
    		// scanf("%d", &B[t]);
    	}

    	for (j=1;j<=N;j++) {
    		temp = A[j];
    		
    		for (i=1;i<=M;i++) {
    			A[j] = temp;
    			if (A[j] > 0 && (j % i == 0)) {
    				A[j] -= B[i];
    			} else continue;
    			if (A[j] <= 0) {
    					cout << i << '\n';
    					break;
    			}
    		}

    		if (A[j] > 0) {
    			cout << -1 << '\n';
    		}
    		
    	}

    }

    return 0;
}
