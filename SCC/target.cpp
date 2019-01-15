#include <iostream>
using namespace std;

static int i, j;

// Driver Function..
void checkSum(int a[], int n, int tar)
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; (j < n) && (i != j); j++)
        {
            if (a[i] + a[j] == tar)
                return;
        }
    }
}

int main()
{
    int n, tar, t;

    // Taking size and target value as Input
    cin >> n >> tar;

    // Dynamically allocating array of size n
    int *a = new int[n];

    // inputting Array elements
    for (t = 0; t < n; t++)
    {
        cin >> a[t];
    }

    // Sorting the array using std::sort
    sort(a, a + n);

    // Driver function
    checkSum(a, n, tar);

    // Output the two Integers..
    cout << a[i] << " " << a[j] << endl;
}