#include <iostream>
using namespace std;

int main()
{
    int n, k, T;

    cin >> T;
    while (T--)
    {
        char i = 'a';
        cin >> n >> k;
        char *st = new char[n];
        int count = 0, ind = 0;
        for (int t = 0; t < n; t++)
        {
            if (count < k)
            {
                st[t] = i;
                i++;
                count++;
            }
            if (count == k)
            {
                i = 'a';
                count = 0;
            }
        }

        cout << st << endl;
    }
}