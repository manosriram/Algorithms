#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
1. any_of
2. none_of
3. all_of
*/
int main() {
    vector<int> oddVector = {1, 3, 5, 7, 11, 13};
    vector<int> evenVector = {2, 4, 6, 8, 10, 12, 14, 16};

    bool all_odd = all_of(oddVector.begin(), oddVector.end(), [](int v) -> bool {return v % 2 != 0;}); // All are Odd.
    cout << all_odd << endl;

    bool all_even = all_of(evenVector.begin(), evenVector.end(), [](int v) -> bool {return v % 2 == 0;}); // All are Even.
    cout << all_even << endl;

    bool none_odd = none_of(oddVector.begin(), oddVector.end(), [](int v) -> bool {return v % 2 != 0;}); // None of them is Odd.
    cout << none_odd << endl;

    bool none_even = none_of(evenVector.begin(), evenVector.end(), [](int v) -> bool {return v % 2 == 0;}); // None of them is Even.
    cout << none_even << endl;

    bool any_even = any_of(evenVector.begin(), evenVector.end(), [](int v) -> bool {return v % 2 == 0;}); // Any one of them is Even.
    cout << any_even << endl;

}