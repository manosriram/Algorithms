#include <iostream>
using namespace std;

bool checkStatus(int n, int Flag[])
{
    int k;
    for (k = 0; k < n; k++)
    {
        if (!Flag[k])
            return 0;
    }
    return 1;
}

int main()
{
    int n, t;
    int i, j;
    cin >> n;
    int *P = new int[n];
    int **Alloc = new int *[n];
    int **Max = new int *[n];
    int **Need = new int *[n];
    int *seq = new int[n];
    int *Flag = new int[n];
    int *Available = new int[n];

    cout << "Available Resources : " << endl;
    cin >> Available[0] >> Available[1] >> Available[2];

    for (t = 0; t < n; t++)
    {
        Alloc[t] = new int[3];
        Max[t] = new int[3];
        Need[t] = new int[3];
        seq[t] = -1;
        Flag[t] = 0;
    }
    cout << "ProcessId " << '\t' << "Allocation " << '\t' << " Max" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> P[i];
        for (j = 0; j < 6; j++)
        {
            if (j <= 2)
            {
                cin >> Alloc[i][j];
            }
            else
            {
                cin >> Max[i][j - 3];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 3; j++)
        {
            Need[i][j] = Max[i][j] - Available[i];
        }
    }
    int index = 0, store = 0;
    while (!checkStatus(n, Flag))
    {
        if (index == n)
            index = 0;

        if (!Flag[index])
        {
            if (Need[index][0] <= Available[0] && Need[index][1] <= Available[1] && Need[index][2] <= Available[2])
            {
                for (t = 0; t < 3; t++)
                {
                    Available[t] += Alloc[index][t];
                }
                Flag[index] = 1;
                seq[store] = index;
                store++;
            }
        }
        index++;
    }

    for (t = 0; t < n; t++)
        cout << seq[t] << " ";
}