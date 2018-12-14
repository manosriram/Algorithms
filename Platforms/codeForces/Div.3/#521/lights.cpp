#include <iostream>
using namespace std;

int main()
{
    int n;

    cin >> n;
    int *a = new int[n];
    int i, count = 0;

    for (i = 0; i < n; i++)
        cin >> a[i];

    for (i = 1; i < n; i++)
    {

        if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1)
        {
            a[i + 1] = 0;
            count++;
            i++;
            continue;
        }
        else
            continue;
    }

    cout << count << endl;
}