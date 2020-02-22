#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    float W = 3.0;
    float weights[] = {1.01, 1.01, 3.0, 2.7, 1.99, 2.3, 1.7};
    int n = sizeof(weights)/sizeof(weights[0]);
    
    int lI = 0, lifts = 0;
    sort(weights, weights+n);

    int cI = n - 1;
    while (lI < cI) {
        if (weights[cI] > 1.99) {
            ++lifts;
        } else if (weights[cI] <= 1.99) {
            if (weights[cI] + weights[lI] <= W) ++lI;

            ++lifts;
        }
        ++cI;
    }
    cout << lifts;
}
