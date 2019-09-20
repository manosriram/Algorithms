#include <string.h>
#include <iostream>
using namespace std;

// Time Complexity : O(m)
int *buildPrefix(string s2) {
    int m = s2.length();
    int *prefix = new int[m + 1];
    prefix[1] = 0;

    int ptr = 0, ind = 0;
    for (int t = 1; t < m; t++) {
        if (s2[t] == s2[ind]) {
            ind++;
            ptr++;
        } else {
            ind = 0;
            ptr = 0;
        }
        prefix[t] = ptr;
    }
    return prefix;
}

// Time Complexity : O(n)
int knuthMorrisPratt(string s1, string s2, int *prefix) {
    int i = 0, j = 0;
    int n = s1.length();
    int m = s2.length();
    while (i < n) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Found at " << (i - j) << endl;
            j = prefix[j - 1];
        } else if (i < n && s2[j] != s1[i]) {
            if (j != 0)
                j = prefix[j - 1];
            else
                i++;
        }
    }
}

// Time Complexity: O(n + m)
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int *prefix;

    prefix = buildPrefix(s2);
    cout << knuthMorrisPratt(s1, s2, prefix) << endl;
}