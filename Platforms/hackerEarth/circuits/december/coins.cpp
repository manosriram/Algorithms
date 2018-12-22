#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    unsigned long long int T, n, k;

    cin >> T;

    while (T--)
    {
        unsigned long long int cur;
        unsigned long long int sum = 0;
        unsigned long long int index = 1;
        unsigned long long int alice = 0, bob = 0;
        cin >> n >> k;
        sum = n;
        while (sum > 0)
        {
            if (n > k && k < pow(10, 9))
            {
                cur = pow(k, index);

                alice += cur;
                sum -= cur;
                if (alice + bob > n)
                {
                    cout << "Bob" << endl;
                    break;
                }

                bob += cur;
                sum -= cur;
                if (alice + bob > n)
                {
                    cout << "Alice" << endl;
                    break;
                }
                index++;
            }
            else
            {
                if (alice + bob >= n)
                {
                    cout << "Alice" << endl;
                    break;
                }
                else
                {
                    cout << "Bob" << endl;
                    break;
                }
            }
        }
    }
}