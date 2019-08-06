#include <iostream>
using namespace std;
int realMax = INT_MIN, realMin = INT_MAX;


void minMax(int *a, int l, int h, int min_, int max_) {
    if (l == h) {
        min_ = max_ = a[l];
    } else {
    if (l == h-1) {
        if (a[l] > a[h]) {
            max_ = a[l];
            min_ = a[h];
        } else {
            max_ = a[h];
            min_ = a[l];
        }
    }
    }

    int mid = (l + h) / 2;
    minMax(a, l, mid, min_, max_);
    minMax(a, mid+1, h, realMin, realMax);

    if (max_ > realMax)
        realMax = max_;
    if (min_ < realMin)
        realMin = min_;

    return;
}

int main() {
    int a[] = {1,2,3,4,5,6,7};
    minMax(a, 0, 6, INT_MAX, INT_MIN);
    
}
