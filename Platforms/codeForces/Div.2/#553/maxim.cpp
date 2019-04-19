#include <iostream>
#include <string.h>
#define forn(t,n) for(t=0;t<n;t++)
using namespace std;

int main() {
  int n;

  cin >> n;
  char *st = new char[n];
  cin >> st;

  int len = 0;
  int min = INT_MAX;
  int diff = 0;
  int i=0;
  int index;

  while (len <= n - 4) {
    if ((st[len] - 'a') < min) {
      min = st[len] - 'a';
      index = len;
    }
    len++;
  }

  if (st[index] > 'm' ) {
    diff += 'z' - st[index] - 25;
    cout << diff << endl;
  } else diff += st[index] - 'a';

  index++;

   if (st[index] > 'm' ) {
    diff += 'z' - st[index];
  } else diff += st[index] - 'c';

   index++;
   
    if (st[index] > 'm' ) {
    diff += 'z' - st[index];
  } else diff += st[index] - 't';

    index++;
    
     if (st[index] > 'm' ) {
    diff += 'z' - st[index];
  } else diff += st[index] - 'g';
    
  cout << diff << '\n';
}
