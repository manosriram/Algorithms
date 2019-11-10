#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
static int n, targetSum;

bool sumOfSubsets(int a[], int currentSum, int currentIndex, int remainingSum) {
    currentSum += a[currentIndex];

    if (currentSum == targetSum)
        return true;

    else if (currentSum < targetSum)
        sumOfSubsets(a, currentSum, currentIndex + 1, remainingSum - a[currentIndex]);

    else
        sumOfSubsets(a, currentSum - a[currentIndex], currentIndex + 1, remainingSum - a[currentIndex]);

}

int main() {
    int a[10] = {5, 4, 1, 6, 2};
    n = sizeof(a)/sizeof(a[0]) + 1;
    targetSum = 3;
    int totalSum = accumulate(a, a+n, 0);

    cout << sumOfSubsets(a, 0, 0, totalSum);

}
