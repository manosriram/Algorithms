#include <iostream>
#include <vector>
#include <algorithm>
#include "Misc.h"
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 100, 111, 23, 44, 124, 90, 67};

    auto lmd = []() { cout << "Hello" << endl; };
    lmd();

    auto it = find_if(v.begin() + 2, v.end(), [](int val) -> int { return val > 100; }); // First value greater than 100.
    cout << *it << endl; // 111

    sort(v.begin(), v.end(), [](int st, int ed) -> bool {return st > ed;}); // Equivalent to sort(v.begin(), v.end(), greater<int>());
    printVector(v); // {124, 111, 100, 90, 67, 44, 23, 3, 2, 1};




}