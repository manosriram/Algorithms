#include "Basic.hpp"

int count1s(int a) {
    int ones = 0;

    while (a) {
        ones += (a & 1);
        a >>= 1;
    }
    return ones;
}

int main() {
    int a = 15;  // 1111

    cout << count1s(a) << endl;
}