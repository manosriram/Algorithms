#include "Basic.hpp"

/*
For Example, let us take a = 75 ie ( 01001011 ) base2 and we want to isolate the
rightmost bit.

0 1 0 0 1 0 1 1
              ^

Step 1: (~a + 1);  We Complement a and add 1. (Similar to Two's Complement).

        0 1 0 0 1 0 1 1 becomes

        1 0 1 1 0 1 0 1

Step 2: Perform AND Operation with the previous result.
So,

        0 1 0 0 1 0 1 1
    &   1 0 1 1 0 1 0 1
        ---------------
        0 0 0 0 0 0 0 1
        ---------------

As the kth bit is 1 (SET), this operation gives us some value but not 0.
Hence, we can conclude that if the result is 0, the bit is not set.
*/

int main() {
    int a = 13;

    a = a & (~a + 1);

    cout << a;
}