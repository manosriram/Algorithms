#include "Basic.hpp"

/*
For Example, let us take a = 75 ie ( 01001011 ) base2 and we want to toggle the
kth bit.

0 1 0 0 1 0 1 1
        ^
        K

Step 1: 1 << (k - 1);  We Left shift '1' (k-1) times ie,

        0 0 0 0 0 0 0 1 becomes

        0 0 0 0 1 0 0 0

Step 2: Perform COMPLEMENT Operation between a and the result.
So,

        0 1 0 0 1 0 1 1
    ^   0 0 0 0 1 0 0 0
        ---------------
        0 1 0 0 0 0 1 1
        ---------------

As the kth bit is 1 (SET), this operation gives us some value but not 0.
Hence, we can conclude that if the result is 0, the bit is not set.
*/

int main() {
    int a = 79, k = 3, b;

    b = 1 << (k - 1);
    b = a ^ b;
    cout << b;
}
