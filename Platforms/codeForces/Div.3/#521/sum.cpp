#include <iostream>
#include <math.h>
using namespace std;

int count(int sum1)
{
    int cnt = 0;
    while (sum1 > 0)
    {
        cnt++;
        sum1 /= 10;
    }
    if (cnt > 1)
        return 0;

    else
        return sum1;
}

int sumDig(int res)
{
    int sum = 0;
    while (res > 0)
    {
        sum += res % 10;
        res /= 10;
    }

    if (!count(sum))
    {
        sum = sumDig(sum);
    }

    // if (count(sum) > 0)
    // {
    //     return sum;
    // }
    return sum;
}

int main()
{
    int t, res = 0;
    int a, n, n1;
    int cnt = 0;
    cin >> n1;
    for (int t1 = 0; t1 < n1; t1++)
    {
        cin >> n >> a;
        for (t = 0; t < n; t++)
        {
            res += pow(10, cnt) * a;
            cnt++;
        }
    }

    int result;
    result = sumDig(res);

    // cout << result << endl;
}