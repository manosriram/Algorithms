#include <iostream>
using namespace std;

bool checkStatus(int n, bool Finish[])
{
    for (int k = 0; k < n; k++)
    {
        if (!Finish[k])
            return false;
    }
    return true;
}

int main()
{
    int n, t;
    cin >> n;
    int *a = new int[n];
    bool *Finish = new bool[n];
    int **Alloc = new int *[n];
    int *Av = new int[n];
    int **Need = new int *[n];
    int **Max = new int *[n];
    int *seq = new int[n];
    int *P = new int[n];
    int index = 0;
    for (t = 0; t < 6; t++)
    {
        Alloc[t] = new int[3];
        Need[t] = new int[3];
        Max[t] = new int[3];
        Finish[t] = false;
        seq[t] = -1;
    }

    cin >> Av[0] >> Av[1] >> Av[2];
    for (t = 0; t < n; t++)
    {
        cin >> P[t];
        for (int j = 0; j < 6; j++)
        {
            if (j <= 2)
                cin >> Alloc[t][j];
            else
            {
                cin >> Max[t][j - 3];
            }
        }
    }

    for (t = 0; t < n; t++)
    {

        for (int j = 0; j < 3; j++)
        {
            Need[t][j] = Max[t][j] - Av[t];
        }
    }

    for (t = 0; t < n; t++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << Need[t][j] << " ";
        }
        cout << endl;
    }

    static int store;
    while (!checkStatus(n, Finish))
    {
        if (index == n)
            index = 0;

        if (!Finish[index])
        {
            if (Need[index][0] <= Av[0] && Need[index][1] <= Av[1] && Need[index][2] <= Av[2])
            {
                for (int j = 0; j < 3; j++)
                    Av[j] += Alloc[index][j];

                Finish[index] = true;
                seq[store] = index;
                store++;
            }
        }
        index++;
    }
    for (t = 0; t < n; t++)
        cout << seq[t] << " ";
}