#include <iostream>
using namespace std;

int findMax(int a, int b)
{
    return (a > b) ? a : b;
}

int findSeq(int a[], int n)
{
    int temp[n];

    for (int t = 0; t < n; t++)
        temp[t] = 1;

    int i = 1, j = 0;
    while (i < n)
    {
        if (i == j)
        {
            i++;
            j = 0;
            continue;
        }

        if (a[i] > a[j])
        {
            temp[i] = findMax(temp[i], temp[j] + 1);
        }
        else
            j++;
    }

    for (int t = 0; t < n; t++)
        cout << temp[t] << " ";
}

int main()
{
    int a[] = {5, 6, 2, 3, 4, 1, 9, 9, 8, 9, 5};
    int n = sizeof(a) / sizeof(a[0]);

    findSeq(a, n);
}