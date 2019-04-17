#include <iostream>
#include <algorithm>
#include <limits.h>
#define ll long long int
#define forn(t,n) for(t=0;t<n;t++)
using namespace std;

int main() {
  ll n,t,max=INT_MIN;

  cin >> n;
  ll *a = new ll[n];
  ll *diff = new ll[n];
  bool e = false;
 
  forn(t,n) {
    cin >> a[t];
  }

  sort(a,a+n);
  
  if (n == 2) {
    cout << (a[1] - a[0]) / 2 << '\n';
    e = true;
  } else {
    forn(t,n-1) {
      int temp = a[t+1] - a[t];
      diff[t] = temp;
      if (temp > max) max = temp;
    }
    sort(diff,diff+n);
    if (n > 2) {
    forn(t,n-1) {
      e = false;
      if (diff[t] == diff[t+1]) {
	e = true;
	break;
      }
    }
    }
  
    (e) ? cout << max << '\n' : cout << -1 << '\n';
  }
}
