#include <iostream>
#include <stack>
using namespace std;
stack<int> st;

int findLongest(string s) {
    int max_ = INT_MIN;
    for (int t=0;t<s.length();t++) {
        if (s[t] == '(')
            st.push(t);
        else {
            st.pop();

            if (!st.empty())
                max_ = max(max_, t - st.top());
            else
                st.push(t);
        }
    }
    return max_;
}

int main() {
st.push(-1);
    string s = ")((())))(())";

    cout << findLongest(s);
}

