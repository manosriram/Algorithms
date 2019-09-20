#include <iostream>
using namespace std;
int store[30][30];

int findWays(int r, int c) {
    if (r == 1 || c == 1) return 1;

    // If value of Matrix at index [r][c] is != -1, then store the current result at this position.
    if (store[r][c] == -1)
        store[r][c] = findWays(r-1,c) + findWays(r,c-1);
    
    // Just return the stored value.
    return store[r][c];
}

int main() {

    // Initialize all Elements in the Matrix to -1
    for (int t=0;t<30;t++) {
        for (int j=0;j<30;j++) {
            store[t][j] = -1;
        }
    }
    // Call the Driver Function.
    cout << findWays(3,3) << '\n';
}