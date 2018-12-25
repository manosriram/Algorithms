#include <iostream>
using namespace std;

int front = -1;
int rear = -1;
int *q = new int[1000];

void insert(int data)
{
    if (front == 1000)
    {
        cout << "Max Overflow.." << endl;
        return;
    }

    else
    {
        if (front == -1)
            front = 0;

        rear += 1;
        q[rear] = data;
    }
}

int btSum(int BT[], int n)
{
    int sum = 0, k;
    for (k = 0; k < n; k++)
        sum += BT[k];

    return sum;
}

int leastAT(int AT[], int n)
{
    int k, ind;
    int min = AT[0];
    for (k = 0; k < n; k++)
    {
        if (AT[k] < min)
        {
            min = AT[k];
            ind = k;
        }
    }
    return ind;
}

int main()
{
    int n, timeQuantum;
    int t, i, j;
    int cur;

    cin >> n >> timeQuantum;

    int *P = new int[n];
    int *Flag = new int[n];
    int *AT = new int[n];
    int *BT = new int[n];
    int *BT1 = new int[n];
    int *CT = new int[n];
    int *WT = new int[n];
    int *TAT = new int[n];
    int *inQ = new int[n];

    for (t = 0; t < n; t++)
    {
        cin >> P[t] >> AT[t] >> BT[t];
        Flag[t] = 0;
        inQ[t] = 0;
    }

    int track = AT[leastAT(AT, n)];
    int btAdd = btSum(BT, n);
    int ind;
    int rem = n;

    while (rem > 0 || btAdd > 0)
    {
        for (t = 0; t < n; t++)
        {
            if (!Flag[t] && !inQ[t])
            {
                if (AT[t] <= track)
                {
                    insert(P[t]);
                    inQ[t] = 1;
                }
            }
        }
        int cur = q[front];
        for (t = 0; t < n; t++)
        {
            if (P[t] == cur)
            {
                ind = t;
                break;
            }
        }
        if (BT[ind] > 0)
        {
            track += timeQuantum;
            cout << track << " ";
            btAdd -= timeQuantum;
            BT[ind] -= timeQuantum;
        }
        else
        {
            track += BT[ind];
            cout << track << " ";
            btAdd -= BT[ind];
            BT[ind] -= BT[ind];
            Flag[ind] = 1;
            inQ[ind] = 0;
            // front++;
        }

        for (i = 0; i < n; i++)
        {
            if (!Flag[i] && inQ[i])
            {
                if (AT[i] <= track)
                {
                    insert(P[i]);
                    inQ[i] = 1;
                }
            }
        }
        if (BT[cur] > 0)
        {
            insert(P[ind]);
            inQ[ind] = 1;
            front++;
        }
        else
        {
            inQ[ind] = 1;
            front++;
        }
    }
}