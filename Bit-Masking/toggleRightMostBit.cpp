#include "Basic.hpp"

/*
A bit is said to be 'SET' if it's value is equal to 1.
For Example, let us take a = 75 ie ( 01001011 ) base2 and we want to check if
4th bit is set or not (K = 4).

0 1 0 0 1 0 1 1

Step 1: (a - 1).

        0 1 0 0 1 0 1 1 becomes

        0 1 0 0 1 0 1 0

Step 2: Perform AND Operation between a and the (a - 1).
So,

        0 1 0 0 1 0 1 1
    &   0 1 0 0 1 0 1 0
        ---------------
        0 1 0 0 1 0 1 0
        ---------------

*/

int main() {
    int a = 75, b;

    b = a & (a - 1);
}