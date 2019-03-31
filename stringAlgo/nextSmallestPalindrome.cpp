#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;

ll getLength(ll n) {
  ll count=0;
  while (n > 0) {
    count++;
    n /= 10;
  }
  return count;
}

ll getNextSmallestPal(ll n) {
  ll temp=0;
  int t;
  ll len = getLength(n);
  ll first;

   
  for (t=0;t<(len/2);t++) {

    temp += (n % 10) * pow(10,t);
    n /= 10;
  }
  first = temp / pow(10,(len/2)-1);

  if (len % 2 == 0) {
  
  if (n % 10 > first) {
  ll overrider=0;
  ll dup = n;

  for (t=0;t<(len/2);t++) {
    overrider += (n % 10) * pow(10,(len/2)-t-1);
    n /= 10;
  }

  dup *= pow(10, len/2);
  dup += overrider;
  cout << dup << endl;
  }
  else if (n % 10 < first) {
    n += 1;

      ll overrider=0;
  ll dup = n;

  for (t=0;t<(len/2);t++) {
    overrider += (n % 10) * pow(10,(len/2)-t-1);
    n /= 10;
  }

  dup *= pow(10, len/2);
  dup += overrider;
  cout << dup << endl;
  }
  } else {
    ll mid = n % 10;
    n /= 10;
    
    if (temp % 10 > first) {
      ll overrider=0;
      ll dup = n;

  for (t=0;t<(len/2);t++) {
    overrider += (n % 10) * pow(10,(len/2)-t-1);
    n /= 10;
  }

  dup *= pow(10, len/2);
  dup += overrider;
    }
    
    cout << overrider << endl;
  }
}


int main() {

  ll n;
  cin >> n;

  getNextSmallestPal(n);
  
}
