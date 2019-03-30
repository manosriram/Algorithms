#include <iostream>
#include <math.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int N, T, D, t;
    cin >> T;
    while (T--)
    {

        cin >> N >> D;
        int *a = new int[N];
        int *visited = new int[N];

        for (int t = 0; t < N; t++)
        {
            cin >> a[t];
            visited[t] = 0;
        }
        quickSort(a, 0, N - 1);

        for (t = N - 1; t > 0; t--)
        {
            if (!visited[t])
            {
                if (abs(a[t] - a[t - 1]) <= D)
                {
                    visited[t] = 1;
                    continue;
                }
                else
                    break;
            }
        }
        if (t == 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}