#include <iostream>
#include<cstdint> 
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    int64_t  x, y, z, sum;

    cin >> x >> y >> z;

    sum = 0;

    int64_t  remSum = 0;

    sum += x / z;
    sum += y / z;

    remSum = ((x % z) + (y % z)) / z;
    sum += remSum % mod;

    int64_t  minim = min((x % z), (y % z));

    cout << (sum % mod) << " " << minim << '\n';
}
