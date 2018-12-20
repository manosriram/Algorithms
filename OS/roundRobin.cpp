#include <iostream>
using namespace std;

int rear = -1;
int front = -1;
int q[1000];

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

int btAdd(int BT[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
        sum += BT[i];

    return sum;
}

int main()
{

    int n, timeQuantum;
    cin >> n >> timeQuantum;

    int *AT = new int[n];
    int *Flag = new int[n];
    int *P = new int[n];
    int *BT = new int[n];

    int btSum, i, j, t;

    for (t = 0; t < n; t++)
    {
        cin >> P[t] >> AT[t] >> BT[t];
        Flag[t] = 0;
    }
    int cur = -1;
    btSum = btAdd(BT, n);
    int track = 0;
    while (btSum > 0)
    {
        for (t = 0; t < n; t++)
        {
            if (!Flag[t])
            {
                if (AT[t] <= track)
                {
                    if (cur != P[t] - 1)
                    {
                        insert(P[t]);
                    }
                }
            }
        }

        if (cur != -1)
            insert(cur);

        for (t = front; t <= rear; t++)
        {
            if (q[t] != 0)
            {
                cur = q[t];
                break;
            }
            else
                continue;
        }

        for (t = front; t <= rear; t++)
        {
            // if (t > 0)
            // {
            if (BT[q[t] - 1] >= timeQuantum)
            {
                btSum -= timeQuantum;
                track += timeQuantum;
                BT[q[t] - 1] -= timeQuantum;
            }
            // }
            if (BT[q[t] - 1] < timeQuantum)
            {
                btSum -= BT[q[t] - 1];
                track += BT[q[t] - 1];
                BT[q[t] - 1] = 0;
            }

            // if (t == 0)
            // {
            //     if (BT[q[t]] >= timeQuantum)
            //     {
            //         btSum -= timeQuantum;
            //         track += timeQuantum;
            //         BT[q[t]] -= timeQuantum;
            //     }
            //     else if (BT[q[t]] < timeQuantum)
            //     {
            //         btSum -= BT[q[t]];
            //         track += BT[q[t]];
            //         BT[q[t]] = 0;
            //     }
            // }
            front++;
            cout << track << " ";
        }

        for (t = 0; t < n; t++)
        {
            if (BT[t] == 0)
                Flag[t] = 1;
        }
    }
}