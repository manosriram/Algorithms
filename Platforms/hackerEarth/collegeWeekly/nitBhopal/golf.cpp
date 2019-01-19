#include <iostream>
using namespace std;
int a1, b1;

bool getRes(int a, int b, int c, int k)
{
    if (abs(a + b + c) == k)
        return 1;
    if (abs(a + b - c) == k)
        return 1;
    if (abs(a - b - c) == k)
        return 1;
    if (abs(-a - b - c) == k)
        return 1;
    if (abs(-a + b + c) == k)
        return 1;
    if (abs(a - b + c) == k)
        return 1;
    if (abs(-a - b + c) == k)
        return 1;
    if (abs(a - b + c) == k)
        return 1;
    if ((a + b + c) == k)
        return 1;
    if ((a + b - c) == k)
        return 1;
    if ((a - b - c) == k)
        return 1;
    if ((-a - b - c) == k)
        return 1;
    if ((-a + b + c) == k)
        return 1;
    if ((a - b + c) == k)
        return 1;
    if ((-a - b + c) == k)
        return 1;
    if ((a - b + c) == k)
        return 1;
}

int main()
{
    int T, k, a, b, c;
    cin >> T;
    while (T--)
    {
        cin >> k;
        cin >> a >> b >> c;

        if (!getRes(a, b, c, k))
        {
            cout << "LOSE" << '\n';
        }
        else
        {
            cout << "WIN" << '\n';
        }
    }
}