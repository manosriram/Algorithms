#include <iostream>
using namespace std;

int main()
{
    string a = "";

    for (char t = 'a'; t < 'p'; t++)
    {
        a += t;
    }

    cout << a << '\n';
}