#include <iostream>
using namespace std;
int totalWeight;

int knapSack(int *prof, int *weights, int n) {
    float *profBYweights = new float[n];
    
    for (int t=0;t<n;t++) {
        profBYweights[t] = prof[t] / weights[t];
    }

    while (totalWeight >= 0) {
 //       getM
    }
}

int main() {
    int prof[] = {10, 5, 15, 7, 6, 18, 3};
    int weights[] = {2, 3, 5, 7, 1, 4, 1};
}
