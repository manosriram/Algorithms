#include <iostream>
#include <string.h>
#define ll long long
using namespace std;

int main()
{
    char n[10000], t[10000];
    int len;

    cin >> len;

    cin >> n >> t;
    cout << std::strcmp(n , t) << endl;
}