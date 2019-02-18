#include <iostream>
#include <string.h>
using namespace std;

int main() {

  int r,c,i,j,n,t;
  char str[100], a[50][50];
  char b[26];
  int cnt=0,trackCount1[26],trackCount2[26];
  
  cin >> r >> c;

  for (t=0;t<26;t++){
    b[t] = 0;
    trackCount1[t] = 0;
    trackCount2[t] = 0;
  }
  
  cout << "Enter String : ";
  cin >> str;

  n = strlen(str);

  for (t=0;t<n;t++) {
    b[int(str[t]) - 65] = str[t];
    trackCount1[int (str[t]) - 65]++;
  }

  for (i=0;i<r;i++) {
    for (j=0;j<c;j++) {
      cin >> a[i][j];

      if (a[i][j] == b[int (a[i][j]) - 65]) {
	trackCount2[int (a[i][j]) - 65]++;
	// cnt++;
      }
    }
  }
  int found=0;

  for (t=0;t<n;t++) {
    if (trackCount2[int(str[t])-65] >= trackCount1[int (str[t])-65]) cnt++;
  }
  if (cnt == strlen(str)) {
    cout << "Word Found!" << endl;
  } else cout << "Word Not Found.." << endl;
  
    
}
