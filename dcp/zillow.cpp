#include <iostream>
using namespace std;


int main() {

  int n;
  cin >> n;
  int **a = new int*[n];

  int t;
  for (t=0;t<n;t++)
    a[t] = new int[n];
  int i,j;

  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  
  int r=0,c=0;
  int curr = a[0][0];
  int sum = 0;
  while (curr != a[n-1][n-1]) {

    if (a[r][c+1] > a[r+1][c]) {
      sum += curr;
      curr = a[r][c];
      c++;
    } else {
      curr = a[r][c];
      sum += curr;
      r++;
    }
  }

  cout << sum << endl;
  
}
