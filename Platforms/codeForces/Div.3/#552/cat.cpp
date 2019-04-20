#include <iostream>
#include <limits.h>
#define ll long long int
#define forn(t,n) for(t=0;t<n;t++)
using namespace std;

bool checkStatus(ll a, ll b, ll c) {
  return (a != -1 || b != -1 || c != -1) ? true : false;
}

ll getIndex(ll a, ll b, ll c) {
  if (a > b && a > c) return 0;
  if (b > a && b > c) return 2;
  return 3;  
}

int main() {
  ll a,b,c,d,e,f,t;
  ll max = INT_MIN;
  cin >> a >> b >> c;
  d = a,e = b,f = c;

  if (a > b && a > c && b == c) {
    cout << a+b+c << '\n';
    exit(0);
  }
  
  ll storeCounter = getIndex(a,b,c);
  ll counter = storeCounter;
  ll count = 0;
  forn(t,3) {
    if (t==0) counter = 0;
    else if (t==1) counter = 6;
    else counter = 3;
    a = d;
    b = e;
    c = f;
    count=0;
    while (a != -1 && b != -1 && c != -1){
    if (counter == 0 || counter == 1 || counter == 4) {
      a--;
    } else if (counter == 2 || counter == 4) {
      b--;
    } else {
      c--;
    }

    counter++;
    count++;
    if (counter == 7) counter = 0;
  }
  
  cout << count - 1 << '\n';
  if (max > count-1) max = count-1;
  }
  cout << max << '\n';
}
