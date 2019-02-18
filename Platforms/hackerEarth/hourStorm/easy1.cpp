#include <iostream>
using namespace std;

int sumNum(int a[],int n) {
  int k,sum=0;
  for (k=0;k<n;k++)
    sum += a[k];

  return sum;
}


int main() {
  int x,t,sum=0,ind,temp;
  char a[5];

  cin >> a;  
  // cout << int(':' - '0') << endl;
  for (t=0;t<5;t++) {
    temp = a[t] - '0';
    if (temp >= 0 && temp <=9) {
      sum += temp;
    } else continue;;
  }
  cin >> x;
  ind=0;
  while (sum % x !=0) {
    sum++;
    ind++;
  }
  cout << ind << endl;

}
