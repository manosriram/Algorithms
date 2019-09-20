#include <iostream>
#include <vector>
#include <algorithm>
#include "Misc.h"
#define NL cout << '\n';
using namespace std;

int main()
{
    vector<int> v = {1, 3, 3, 5, 7};
    printVector(v); // {1, 3, 3, 5, 7}
    reverse(v.begin(), v.end());
    printVector(v); // {7, 5, 3, 3, 1}

    vector<int> v1(3);
    printVector(v1); // {0, 0, 0}
    reverse_copy(v.begin(), v.end(), v1.begin());
    printVector(v1); // {1, 3, 3}
}