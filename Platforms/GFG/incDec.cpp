#include <iostream>
using namespace std;

int searchBinary(int *a, int n) {
  int low = 0, high = n-1, mid = (low + high) / 2;

  
  while (low <= high) {
    
    if (low == high)
      return a[mid];

    cout << low << " " << high << endl;

    if (a[mid-1] < a[mid] && a[mid + 1] < a[mid])
      return a[mid];
    
    if (a[mid - 1] >= a[mid]) {
      high = mid - 1;
      mid = (low + high) / 2;
    } else {
      low = mid + 1;
      mid = (low + high) / 2;
    }
  }
  cout << low << " " << high << endl;
  return (high < 0 || low > n-1) ? a[mid] : INT_MAX;
}

int main() {
  int n;
  cin >> n;
  int *a = new int[n];

  for (int t=0;t<n;t++)
    cin >> a[t];
  
  cout << searchBinary(a, n) << endl;

}
