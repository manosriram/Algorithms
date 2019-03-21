#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;

ll getLength(int n)
{
    ll cn = 0;
    while (n > 0)
    {
        cn++;
        n /= 10;
    }
    return cn;
}

int checkSingle(int n)
{
    int hits;

    while (n > 0)
    {
        if ((n % 10) % 2 == 0)
            hits++;

        n /= 10;
    }
    return hits;
}

int checkNext(int one, int two, int len, int n)
{
    int back = len - two - 1;
    int count = len - 1;
    while (back != 0 || one != 0)
    {
        if (one > 0)
        {
            int fr = n;
            while (fr >= 10)
                fr /= 10;

            n -= fr * pow(10, count);
            count--;
            one--;
        }
        if (back > 0)
        {
            n /= 10;
            back--;
        }
    }
    return n;
}

int main()
{
    int n, t, j;
    int len1;
    cin >> len1;
    cin >> n;
    int len = getLength(n);
    if (len1 == len)
    {
        int hit = 0;
        int rem = checkSingle(n);
        for (t = 0; t < len; t++)
        {
            for (j = t + 1; j < len; j++)
            {
                if (checkNext(t, j, len, n) % 2 == 0)
                    hit++;
            }
        }
        cout << (hit + rem) << endl;
    }
}