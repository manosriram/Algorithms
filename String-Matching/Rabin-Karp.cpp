#include <iostream>
#include <string>
#include <math.h>
using namespace std;

uint32_t hash_function(string s) {
    int mx = 0;
    for (int t=0;t<s.length();++t) {
        mx += (s[t] - 'a' + 1) * pow(10, s.length() - t - 1);
    }
    return mx;
}

bool is_substring(string a, string b, uint32_t hash) {
    // Hash for 'a' to begin with.
    auto h = hash_function(a.substr(0, b.length()));

    for (int t=0;t<a.length();++t) {
        // If the hashes match.
        if (h == hash) {
            return true;
            int ina = t, inb = 0;
            // If hashes match, check is they really are equal.
            while (a[ina] == b[inb]) {
                ++ina, ++inb;
            }
            if (inb == b.length()) return true;
        }

        // Rolling hash.
        h -= pow(10, b.length()-1) * (a[t] - 'a' + 1);
        h  = (h * 10) + (a[t+b.length()-1] - 'a' + 1);
    }

    return false;
}

int main() {
    string a = "abc", b = "abdz";
    uint32_t hash = hash_function(b);
    cout << hash << endl;
    return 1;

    cout << is_substring(a, b, hash);
}

