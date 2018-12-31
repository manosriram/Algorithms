#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n, i;
    int skp = 1, cur = 0, cnt = 0;
    cin >> n;
    char *s = new char[n];
    char *s1 = new char[n];
    s1[0] = s[0];
    cin >> s;

    while (cur <= n)
    {
        s1[cnt++] = s[cur];
        cur += skp;
        skp++;
    }
    cout << s1 << endl;
}