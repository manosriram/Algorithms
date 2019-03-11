#include <iostream>
using namespace std;

int sumTr(int a[], int n)
{
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];

    for (int t = 0; t < n; t++)
        cin >> a[t];

    sumTr(a, n);
}