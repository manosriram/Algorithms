#include <iostream>
using namespace std;

/* 
    How many ways are there to reach from the first element to the last element in a "n x m" matrix said that we can only move RIGHT and DOWN.
*/

int getTotalWays(int n, int m)
{
    if (n == 1 || m == 1)
        return 1;

    return getTotalWays(n - 1, m) + getTotalWays(n, m - 1);
}

int main()
{
    int r, c;
    int t, i, j, k;
    cout << "Number of Rows : ";
    cin >> r;
    cout << "Number of Columns : ";
    cin >> c;

    cout << "Number of Ways = " << getTotalWays(r, c) << endl;
}