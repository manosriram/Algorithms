#include <iostream>
#include <math.h>
using namespace std;
void quick(int a[],int l,int u)
{
  int i,j;
   int p,temp;
   if(l<u)
   {
   p=a[l];
   i=l;
   j=u;
    while(i<j)
   {
      while(a[i] <= p && i<j )
	 i++;
      while(a[j]>p && i<=j )
	   j--;
      if(i<=j)
      {
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;}
  }
  temp=a[j];
  a[j]=a[l];
  a[l]=temp;
  
  quick(a,l,j-1);
  quick(a,j+1,u); 
 }
}
int main() {
  int n,t;
  int sum=0;
  cin >> n;
  int *a = new int[n];
  int *b = new int[n];

  for (t=0;t<n;t++) {
    cin >> a[t];
  }
  for (t=0;t<n;t++) {
    cin >> b[t];
  }

  quick(a,0,n-1);
  quick(b,0,n-1);
  
  for (t=0;t<n;t++) {

    sum += abs(a[t]-b[t]);
  }
  cout << sum << '\n';
}
