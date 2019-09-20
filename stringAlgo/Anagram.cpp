#include <string.h>
#include <iostream>
#include "unordered_map"
using namespace std;

bool isAnagram(string s1, string s2, unordered_map<char, char> ump) {
    for (int t = 0; t < s1.length(); t++)
        ump[s1[t]] = s1[t];

    int cnt = 0;
    for (int t = 0; t < s2.length(); t++)
        if (ump[s2[t]] == s2[t])
            cnt++;

    return (cnt == s1.length());
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    unordered_map<char, char> ump;
    cout << isAnagram(s1, s2, ump) << endl;
}