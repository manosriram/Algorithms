#include <iostream>
using namespace std;

int rightShiftN(int a, int n) { return (a >> n); }

int leftShiftN(int a, int n) { return (a << n); }

int rightShift(int a) { return (a >> 1); }

int leftShift(int a) { return (a << 1); }

int COMP(int a) { return ~a; }

int XOR(int a, int b) { return (a ^ b); }

int OR(int a, int b) { return (a | b); }

int AND(int a, int b) { return (a & b); }
