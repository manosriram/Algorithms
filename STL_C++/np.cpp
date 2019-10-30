#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<char> v;
    string s = "abc";
    
    for (int t=0;t<s.length();t++) {
        v.push_back(s[t]);
    }
    
    cout << s << endl;
    while (next_permutation(v.begin(), v.end())) {
        for (auto t : v)
            cout << t;

        cout << endl;
    }

}
