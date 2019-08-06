#include <iostream>
#include <utility> 
using namespace std;
pair<int, int> pr(INT_MIN, INT_MAX);

void minMax(int a[], int low, int high) {
    for (int t=low;t<=high;t++) {
        if (a[t] > pr.first)
            pr.first = a[t];
        
        if (a[t] < pr.second)
            pr.second = a[t];
    }
    return;
}

void findMinMax(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        findMinMax(a, low, mid);
        findMinMax(a, mid + 1, high);
        minMax(a, low, high);
    }
}

int main() {
    int a[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);

    findMinMax(a, 0, n - 1);
    cout << pr.first << " " << pr.second << endl;
}