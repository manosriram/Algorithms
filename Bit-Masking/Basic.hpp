#include <math.h>
#include <iostream>
using namespace std;

int reverseBinary(int a) {
    int revA = a, s = sizeof(a);

    while (a) {
        revA <<= 1;
        revA |= (a & 1);
        a >>= 1;
        --s;
    }
    revA <<= s;
    return revA;
}

bool powerOf2(int a) { return ((a & (a - 1)) == 0); }

void printBinaryRep(int a) {
    string temp = std::to_string((a & 1));
    while (a) {
        a = a >> 1;
        temp = std::to_string(a & 1) + temp;
    }
    cout << temp;
    cout << endl;
    return;
}

int rightShiftN(int a, int n) { return (a >> n); }

int leftShiftN(int a, int n) { return (a << n); }

int rightShift(int a) { return (a >> 1); }

int leftShift(int a) { return (a << 1); }

int COMP(int a) { return ~a; }

int XOR(int a, int b) { return (a ^ b); }

int OR(int a, int b) { return (a | b); }

int AND(int a, int b) { return (a & b); }
