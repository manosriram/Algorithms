#include <iostream>
#include <vector>
#include <algorithm>
#include "Misc.h"
#define NL cout << '\n';
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    printVector(v);
    rotate(v.begin(), v.begin() + 2, v.end());
    printVector(v);

    vector<int> u(5);
    rotate_copy(v.begin(), v.begin() + 2, v.end(), u.begin());
    printVector(u);
}