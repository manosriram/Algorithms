#include <iostream>
using namespace std;

void merge(int a[], int low, int mid, int high) {
    int i = 0, j = 0, k = 1;

    int n1 = (mid - low) + 1, n2 = high - mid;
    int L[100], R[100];

    for (i=0; i < n1; i++)
        L[i] = a[low + i];

    for (j=0; j < n2; j++)
        R[j] = a[mid + j + 1];

    i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k++] = L[i];
            i++;
        }
        else
        {
            a[k++] = R[j];
            j++;
        }
    }


    for (;i<n1;i++)
        a[k++] = L[i];

    for (;j<n2;j++)
        a[k++] = R[j];

    return;
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int a[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, n - 1);

    for (int t = 0; t < n; t++)
        cout << a[t] << " ";
}
