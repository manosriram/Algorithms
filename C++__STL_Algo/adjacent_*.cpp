#include <iostream>
#include <vector>
#include <algorithm>
#include "Misc.h"
using namespace std;

template<typename FwdIt>
auto adjacent_count (FwdIt fst, FwdIt lst) {
    auto c = 0;
    while (true) {
        fst = adjacent_find(fst, lst);
        if (fst == lst)
            return c;
        c++;
        fst++;
    }
    return c;
}

int main() {
    vector<int> v = {0, 5, 2, 2, 3, 1, 4, 4};

    auto it = adjacent_find(v.begin(), v.end()); // returns the iterator of the element which is repeated, else returns iterator pointing to the last.
    cout << *it << endl;
    cout << distance(v.begin(), it) << endl;


    auto it2 = adjacent_find(v.begin(), v.end(), greater<>()); // returns first element greater than the found element.
    cout << *it2 << endl;
    cout << distance(v.begin(), it2) << endl;
    
    cout << adjacent_count(v.begin(), v.end()) << endl;
}