#include <iostream>
#include <vector>
#include <algorithm>
#include "Misc.h"
#define NL std::cout << '\n';

/*
1. set_union (both a and b)
2. set_intersection (common elements in a and b)
3. set_difference (elements present only in a but not in b)
4. set_symmetric_difference (elements present in both a and b but not in common)
*/

int main()
{
    std::vector<int> v1 = {0, 1, 2, 3, 4, 5};
    std::vector<int> v2 = {4, 5, 6, 7, 8, 9};
    std::vector<int> v3, v4, v5, v6;

    std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v4));
    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v5));
    std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v6));
    
    NL;
    std::cout << "set_union "; printVector(v3);
    std::cout << "set_intersection ";printVector(v4);
    std::cout << "set_difference "; printVector(v5);
    std::cout << "set_symmetric_difference "; printVector(v6);
    NL;
}