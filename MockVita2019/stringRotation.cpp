#include <iostream>
#include <string.h>
using namespace std;
string in;

bool isSubString(string s1, string s2) {

    for (int t=0;(s2.length()-1+t)<s1.length();t++) {
        if (s1.substr(t, s2.length()) == s2) return true;
    }
    return false;
}

char rotateRight(long long int magnitude)
{
    string temp;
    temp = in.substr(0, in.length()-magnitude);
    in = in.substr(in.length() - magnitude, in.length());
    in += temp;
    return in[0];
}

char rotateLeft(long long int magnitude)
{
    string temp;
    temp = in.substr(0, magnitude);
    in = in.substr(magnitude, in.length());
    in += temp;
    return in[0];
}

int main()
{
    long long int T, magnitude;
    string res, originalString;
    char dir;
    cin >> in >> T;
    originalString = in;
    while (T--)
    {
        cin >> dir >> magnitude;

        if (dir == 'L')
        {
            res += rotateLeft(magnitude);
        }
        if (dir == 'R')
        {
            res += rotateRight(magnitude);
        }
    }
    (isSubString(originalString, res)) ? cout << "YES" : cout << "NO";
  return 0;
}