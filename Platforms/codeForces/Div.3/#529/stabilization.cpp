#include <iostream>
using namespace std;

int main()
{
    int n, t;
    int *a = new int[n];
    int max = INT_MIN;
    cin >> n;
    for (t = 0; t < n; t++)
    {
        cin >> a[t];
        if (a[t] > max)
            max = a[t];
    }
    int findMax = INT_MIN;
    int findMin = INT_MAX;
    for (t = 0; t < n; t++)
    {
        if (a[t] != max)
        {
            if (a[t] < findMin)
                findMin = a[t];
            else if (a[t] > findMax)
                findMax = a[t];
        }
    }
    if (n == 2)
        cout << 0 << endl;
    else
        cout << findMax - findMin << endl;
}