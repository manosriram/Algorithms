#include <iostream>
using namespace std;

int main()
{
    int T, x, dirCount;
    cin >> T;
    while (T--)
    {
        cin >> dirCount >> x;

        char temp[dirCount];
        int store[dirCount + 1];
        int count = 1;

        for (int t = 0; t < dirCount + 1; t++)
        {
            store[t] = t;
        }

        cin >> temp;
        store[(x % dirCount)] = x;

        for (int k = 0; k < dirCount; k++)
        {
            if (temp[k] == 'L')
            {
                x -= 1;
            }
            else
                x += 1;

            if (store[(x % dirCount)] != x)
            {
                store[(x % dirCount)] = x;
                count++;
            }
            else
                continue;
        }
        cout << count << '\n';
    }
}