#include <iostream>
using namespace std;

bool findPrime(int p, int currentNumber)
{
    if (currentNumber == p / 2)
        return true;
    if (p % currentNumber == 0)
        return false;
    return findPrime(p, currentNumber + 1);
}

int main()
{
    int n;
    cin >> n;
    findPrime(n, 2) ? cout << "Prime" << '\n' : cout << "Not Prime" << '\n';
}