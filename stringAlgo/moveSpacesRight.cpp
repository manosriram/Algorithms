#include <string.h>
#include <iostream>
using namespace std;

string moveSpacesRight(string s) {
    int n = s.end() - s.begin();

    int i = n - 1, j = n - 2;
    while (j >= 0) {
        if (s[j] == ' ') {
            for (int k = j;k < i;k++) {
                s[k] = s[k+1];
            }
            s[i] = '$';
            --i;
        }
        --j;
    }
    return s;
}

int main() {
    string s = "move these spaces to the right";
    s = moveSpacesRight(s);
    cout << s << endl;
}