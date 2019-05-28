#include <iostream>
using namespace std;

string whatTime(int n)
{
    string total = "";
    int h, m, s;

    h = n / 3600;
    m = (n - (3600 * h)) / 60;
    s = ((n - (3600 * h)) - (60 * m));

    total += std::to_string(h);
    total += ":";
    total += std::to_string(m);
    total += ":";
    total += std::to_string(s);

    return total;
}

int main()
{
    int n;
    cin >> n;
    cout << whatTime(n) << endl;
}