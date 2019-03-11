#include <iostream>
#include <math.h>
using namespace std;

int partition(int A[], int start, int end)
{
    int i = start + 1;
    int piv = A[start]; //make the first element as pivot element.
    for (int j = start + 1; j <= end; j++)
    {
        /*rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. */

        if (A[j] < piv)
        {
            swap(A[i], A[j]);
            i += 1;
        }
    }
    swap(A[start], A[i - 1]); //put the pivot element in its proper place.
    return i - 1;             //return the position of the pivot
}

void quick_sort(int A[], int start, int end)
{
    if (start < end)
    {
        //stores the position of pivot element
        int piv_pos = partition(A, start, end);
        quick_sort(A, start, piv_pos - 1); //sorts the left side of pivot.
        quick_sort(A, piv_pos + 1, end);   //sorts the right side of pivot.
    }
}

int main()
{
    int n;
    cin >> n;

    int *a = new int[n];
    int t;

    for (t = 0; t < n; t++)
        cin >> a[t];

    quick_sort(a, 0, n - 1);

    int count = 0, mid;

    if (n % 2 == 0)
    {
        if (a[(n / 2)] < a[(n / 2) - 1])
            mid = a[n / 2];
        else
            mid = a[(n / 2) - 1];
    }

    for (t = 0; t < n; t++)
    {
        if (a[t] < mid)
            count += mid - a[t];
        else
            count += a[t] - mid;
    }
    cout << count << endl;
}