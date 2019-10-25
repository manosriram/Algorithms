#include "Basic.hpp"

/*
For Example, let us take a = 32 ie ( 100000 ) base2 and we want to check whether
the number is a power of 2 or not.

Step 1: (a - 1);  We decrement the value by 1.

        1 0 0 0 0 0 becomes

        0 1 1 1 1 1

Step 2: Perform AND Operation with the previous result and original a.
So,

        1 0 0 0 0 0 0 0
    &   0 1 1 1 1 1 1 1
        ---------------
        0 0 0 0 0 0 0 0
        ---------------

So, if the result is 0, the number is a power of 2. Else, it isn't.
*/

int main() {
    int n = 32;

    cout << powerOf2(n) << endl;
}