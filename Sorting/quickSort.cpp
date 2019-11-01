#include <iostream>
using namespace std;

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low, j = high;

    while (i < j) {
        do {
            ++i;
        } while(a[i] <= pivot);

        do {
            --j;
        }  while(a[j] > pivot);

        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[low], a[j]);
    return j;
}


void quickSort(int a[], int low, int high) {

    if (low < high) {
        int j = partition(a, low, high);
        quickSort(a, low, j);
        quickSort(a, j+1, high);
    }

}


int main() {
    int a[] = {5, 3, 9, 12, 44, 21, 1, 4, 15};
    int n = sizeof(a)/sizeof(a[0]);

    quickSort(a, 0, n);

    for (int t=0;t<n;++t)
        cout << a[t] << " ";
}
