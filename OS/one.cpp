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
    int k;
    int min = AT[0];
    for (k = 0; k < n; k++)
    {
        if (AT[k] < min)
            min = AT[k];
    }
    return min;
}

int main()
{
    int n, timeQuantum;
    int t, i, j;
    int btAdd, cur;

    cin >> n >> timeQuantum;

    int *P = new int[n];
    int *Flag = new int[n];
    int *AT = new int[n];
    int *BT = new int[n];
    int *BT1 = new int[n];
    int *CT = new int[n];
    int *WT = new int[n];
    int *TAT = new int[n];
    int *Completed = new int[n];

    for (t = 0; t < n; t++)
    {
        cin >> P[t] >> AT[t] >> BT[t];
        BT1[t] = BT[t];
        Flag[t] = 0;
        Completed[t] = 0;
    }
    int cnt = 0;
    int rp = n;
    btAdd = btSum(BT, n);
    int track = 0;
    // int track = leastAT(AT, n);
    int completedCount = 1;

    while (rp != 0)
    {
        if (BT[i] > timeQuantum)
        {
            BT[i] = BT[i] - timeQuantum;
            track += timeQuantum;
            // cout << track << " ";
        }
        else if (BT[i] <= timeQuantum && BT[i] > 0)
        {
            CT[i] = track;
            track += BT[i];
            BT[i] = BT[i] - BT[i];
            rp--;
            // cout << track << " ";
        }

        i++;
        if (i == n)
        {
            i = 0;
        }
    }

    for (t = 0; t < n; t++)
        cout << CT[t] << " ";

    // float wtSum = 0, tatSum = 0;
    // for (t = 0; t < n; t++)
    // {
    //     TAT[t] = CT[t] - AT[t];
    //     WT[t] = TAT[t] - BT1[t];
    //     tatSum += TAT[t];
    //     wtSum += WT[t];
    // }
    // float AWT, ATAT;

    // AWT = wtSum / n;
    // ATAT = tatSum / n;

    // front = 0;

    // // cout << AWT << " " << ATAT << endl;

    // for (t = 0; t < n; t++)
    //     cout << CT[t] << " ";

    // cout << AWT << " " << ATAT << endl;
}