#include <iostream>
using namespace std;

int minTrack(int n,int AT[]) {
  int k,ind;
  int min=AT[0];
  for (k=0;k<n;k++) {
    if (AT[k] < min){ min = AT[k]; ind = k;}
  }
  return ind;
}

void swapER(int i1,int i2,int arr[]) {
  int temp;
  temp = arr[i1];
  arr[i1] = arr[i2];
  arr[i2] = temp;
}

int main() {

  int n;
  cin >> n;
  int *AT = new int[n];
  int *P = new int[n];
  int *BT = new int[n];
  int *CT = new int[n];
  int t,i,j;
  for (t=0;t<n;t++){
    cin >> P[t] >> AT[t] >> BT[t]; 
  }
  int track;

  for (t=0;t<n;t++) {
    for (i=t+1;i<n;i++) {
      if (AT[t] > AT[i]) {
	swapER(t,i,AT);
	swapER(t,i,BT);
	swapER(t,i,P);
      }
    }
  }
  CT[0] = BT[0];
  track = CT[0];
  for (t=1;t<n;t++) {
    track += BT[t];
    if (AT[t] - CT[t-1] > 0) track += (AT[t] - CT[t-1]);
    CT[t] = track;
  }
  cout << endl;
  for (t=0;t<n;t++) {
    cout << P[t] << " " << AT[t] << " " << BT[t] << '\n';
  }
  cout << endl;
  for (t=0;t<n;t++) {
    cout << CT[t] << endl;
  }
  
}
