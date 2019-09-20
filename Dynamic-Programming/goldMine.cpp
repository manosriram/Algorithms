#include <iostream>
using namespace std;

int twoMax(int a, int b)
{
    return (a > b) ? a : b;
}

int threeMax(int a, int b, int c)
{
    return (a > b && a > c) ? a : (b > a && b > c) ? b : c;
}

int findMaxMines(int r, int c, int maxRowInd, int *a[r])
{
    int start = a[maxRowInd][0];

    int sum = start;
    int col = c - 1;
    int rowInd = maxRowInd, colInd = 0;
    while (col--)
    {
        if (rowInd == 0 && colInd != c - 1)
        {
            sum += twoMax(a[rowInd][colInd + 1], a[rowInd + 1][colInd + 1]);
            rowInd = (a[rowInd][colInd + 1] > a[rowInd + 1][colInd + 1]) ? rowInd : rowInd + 1;
            colInd += 1;
        }
        else if (rowInd == r - 1 && colInd != c - 1)
        {
            sum += twoMax(a[rowInd][colInd + 1], a[rowInd - 1][colInd + 1]);
            rowInd = (a[rowInd][colInd + 1] > a[rowInd - 1][colInd + 1]) ? rowInd : rowInd - 1;
            colInd++;
        }
        else
        {
            sum += threeMax(a[rowInd][colInd + 1], a[rowInd - 1][colInd + 1], a[rowInd + 1][colInd + 1]);
            rowInd = (a[rowInd][colInd + 1] > a[rowInd - 1][colInd + 1] && a[rowInd][colInd + 1] > a[rowInd + 1][colInd + 1]) ? rowInd : (a[rowInd + 1][colInd + 1] > a[rowInd - 1][colInd + 1] && a[rowInd + 1][colInd + 1] > a[rowInd][colInd + 1]) ? (rowInd + 1) : rowInd - 1;
            colInd++;
        }
    }
    return sum;
}

int main()
{
    int r, c;
    cin >> r >> c;

    int *a[r];

    for (int t = 0; t < c; t++)
        a[t] = new int[c];

    int max = INT_MIN, maxRowInd;
    for (int t = 0; t < r; t++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[t][j];
            if (j == 0)
            {
                if (a[t][0] > max)
                {
                    max = a[t][0];
                    maxRowInd = t;
                }
            }
        }
    }

    cout << findMaxMines(r, c, maxRowInd, a) << endl;
}