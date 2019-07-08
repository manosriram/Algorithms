#include <iostream>
#include <vector>
#include <algorithm>
#include "Misc.h"
#define NL cout << '\n';
using namespace std;

/*
1. set_union (both a and b)
2. set_intersection (common elements in a and b)
3. set_difference (elements present only in a but not in b)
4. set_symmetric_difference (elements present in both a and b but not in common)
*/

int main()
{
    vector<int> v1 = {0, 1, 2, 3, 4, 5};
    vector<int> v2 = {4, 5, 6, 7, 8, 9};
    vector<int> v3, v4, v5, v6;

    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v4));
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v5));
    set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v6));
    
    NL;
    cout << "set_union "; printVector(v3);
    cout << "set_intersection ";printVector(v4);
    cout << "set_difference "; printVector(v5);
    cout << "set_symmetric_difference "; printVector(v6);
    NL;
}