#include <iostream>
#include <limits.h>
#define ll long long int
#define forn(t,n) for(t=0;t<n;t++)
using namespace std;

int main() {

  ll sum,t,max=INT_MIN;
  ll *a = new ll[5];
  
  forn(t,4) {
    cin >> a[t];
    if (a[t] > max) max = a[t];
  }

  forn(t,4) {
    if (a[t] != max) {
      cout << (max - a[t]) << " ";
    }
  } 
}

