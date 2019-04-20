#include <iostream>
#define forn(i,n) for(i=0;i<n;i++)
#define ll long long int
using namespace std;

int main() {
  ll n,T;
  ll t;
  
  cin >> n >> T;
  
  ll *si = new ll[n];
  ll *bi = new ll[n];
  ll temp;
  bool got = false;
  forn(t,n) {
    cin >> si[t] >> bi[t];
    if (si[t] == T) {
      temp = t+1;
      got = true;
  }
  }

  if (got) {
    cout << temp << '\n';
    exit(0);
  }
  
  bool flag = false;
  while (!flag) {
    forn(t,n) {
      
      if (si[t] >= T) {
	cout << t+1 << '\n';
	flag=true;
	break;
      }

       si[t] += bi[t];

        if (si[t] >= T) {
	cout << t+1 << '\n';
	flag=true;
	break;
      }
    }
  }
}
