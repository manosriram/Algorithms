#include "./Basic.hpp"

/*
A bit is said to be 'SET' if it's value is equal to 1.
For Example, let us take a = 75 ie ( 01001011 ) base2 and we want to check if
4th bit is set or not (K = 4).

0 1 0 0 1 0 1 1
        ^
        K

Step 1: 1 << (k - 1);  We Left shift '1' (k-1) times ie,

        0 0 0 0 0 0 0 1 becomes

        0 0 0 0 1 0 0 0

Step 2: Perform AND Operation between a and the result.
So,

        0 1 0 0 1 0 1 1
    &   0 0 0 0 1 0 0 0
        ---------------
        0 0 0 0 1 0 0 0
        ---------------

As the kth bit is 1 (SET), this operation gives us some value but not 0.
Hence, we can conclude that if the result is 0, the bit is not set.
*/

int main() {
    int a = 75, k = 4, b;

    b = 1 << (k - 1);
    b = a & b;

    if (b)
        cout << "Kth Bit is Set." << '\n';

    else
        cout << "Kth Bit is not Set." << '\n';
}