#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    ll x, y, z, sum;

    cin >> x >> y >> z;

    sum = 0;

    ll remSum = 0;

    sum += x / z;
    sum += y / z;

    remSum = ((x % z) + (y % z)) / z;
    sum += remSum;

    ll minim = min((x % z), (y % z));

    cout << sum << " " << minim << '\n';
}