#include <iostream>
using namespace std;

int getMin(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int r, c, i, j;
    cin >> r >> c;

    int temp[r][c], a[r][c], path[r][c];

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            cin >> a[i][j];
            temp[i][j] = 0;
            path[i][j] = 0;
        }
    }
    temp[0][0] = a[0][0];

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (i == 0 && j == 0)
                continue;

            if (i == 0)
                temp[i][j] = temp[i][j - 1] + a[i][j];

            else if (j == 0)
                temp[i][j] = temp[i - 1][j] + a[i][j];

            else
                temp[i][j] = a[i][j] + getMin(temp[i - 1][j], temp[i][j - 1]);

            // path[][] = 1;
        }
    }

    int row = r - 1;
    int col = c - 1;
    cout << a[r - 1][c - 1] << " -> ";
    while (1)
    {
        if (row != 0)
        {

            if (temp[row - 1][col] < temp[row][col - 1])
            {
                row--;
            }
            else
            {
                col--;
            }
        }
        else
        {
            for (int t = row; t >= 0; t--)
            {
                cout << a[0][col - 1] << " -> ";
                col--;
            }
            break;
        }
        cout << a[row][col] << " -> ";
    }
    cout << endl;
}