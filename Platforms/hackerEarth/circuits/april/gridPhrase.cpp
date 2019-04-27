#include <iostream>
using namespace std;

int main()
{
    int r, c, count = 0;
    cin >> r >> c;

    char a[r][c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }

    int len = r * c;
    int i = 0, j = 0;
    while (len--)
    {
        if (a[i][j] == 's' && a[i - 1][j + 1] == 'a' && a[i - 2][j + 2] == 'b' && a[i - 3][j + 3] == 'a')
            count++;

        if (a[i][j] == 's' && a[i + 1][j + 1] == 'a' && a[i + 2][j + 2] == 'b' && a[i + 3][j + 3] == 'a')
            count++;

        if (a[i][j] == 's' && a[i][j + 1] == 'a' && a[i][j + 2] == 'b' && a[i][j + 3] == 'a')
            count++;

        if (a[i][j] == 's' && a[i + 1][j] == 'a' && a[i + 2][j] == 'b' && a[i + 3][j] == 'a')
            count++;

        j++;
        if (j == r - 1)
        {
            i++;
            j = 0;
        }
    }
    cout << count << '\n';
}