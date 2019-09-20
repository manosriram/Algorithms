#include <string.h>
#include <iostream>
using namespace std;

// Time Complexity : O(m * n)
int matchPattern(string s1, string s2) {
    int i, j, back_;

    for (i = 0; i < s1.length(); i++) {
        back_ = i;
        for (j = 0; j < s2.length(); j++) {
            if (s1[back_] == s2[j]) {
                back_++;
                continue;
            } else {
                break;
            }
        }
        if (j == s2.length())
            return i;
    }
    return -1;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << matchPattern(s1, s2) << endl;
}