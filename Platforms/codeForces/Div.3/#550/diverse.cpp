#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#define forn(i,n) for(i=0;t<n;t++)
using namespace std;

int main() {
  int T;
  cin >> T;
  char *str = new char[100];
  int *a = new int[100];
  
  while (T--) {
    int t;
    cin >> str;
    int len = strlen(str);
    
    forn(t,len-1) {
      a[t] = abs((str[t] - 'a') - (str[t+1] - 'a'));
    }

  sort(a,a+len-1);
  bool br = false;
  
  forn(t,len) {
    if (a[t] == (a[t+1] - 1) || a[t] == a[t+1]) continue;
    else {
      cout << " breaking.." << t << endl;
      br = true;
      break;
    }
  }

  if (br) {
    cout << "no" << '\n';
      } else cout << "yes" << '\n';
  }
}
