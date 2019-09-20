#include <iostream>
#include <vector>
#include <algorithm>
#define NL cout << '\n';
using namespace std;

int main()
{
    vector<int> v = {1, 3, 3, 5, 7};

    auto it1 = lower_bound(v.begin(), v.end(), 3);
    auto it2 = lower_bound(v.begin(), v.end(), 4);
    auto it3 = lower_bound(v.begin(), v.end(), 6);


    (it1 != v.end()) ? cout << *it1 : cout << "Not found.";
    NL;
    (it2 != v.end()) ? cout << *it2 : cout << "Not found.";
    NL;
    (it3 != v.end()) ? cout << *it3 : cout << "Not found.";
    NL;

}