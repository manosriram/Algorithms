#include <string.h>
#include <iostream>
using namespace std;

string moveSpacesLeft(string s) {
    int n = s.end() - s.begin();

    int i = 0, j = 1;
    while (j < n) {
        if (s[j] == ' ') {
            for (int k = j;k > i;k--) {
                s[k] = s[k-1];
            }
            s[i] = ' ';
            ++i;
        }
        ++j;
    }
    return s;
}

int main() {
    string s = "move these spaces to the left";
    s = moveSpacesLeft(s);
    cout << s << endl;
}