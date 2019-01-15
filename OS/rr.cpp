#include <iostream>
#define max 400
using namespace std;
int front = -1, rear = -1;
int *q = new int[max];

void pushQ(int data)
{
    if (front == -1)
        front = 0;

    rear++;
    q[rear] = data;
}

void pushQueueElements(int n, int Flag[], int inQ[], int track, int AT[])
{
    int t;
    for (t = 0; t < n; t++)
    {
        if (!Flag[t] && !inQ[t])
        {
            if (AT[t] <= track)
            {
                pushQ(t);
            }
        }
    }
}

int getMinTrack(int AT[], int n)
{
    int k, min = AT[0], ind;
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
    bool done = false;
    int toPush = 0;
    int n, tq;
    int t, i, btSum = 0;

    cin >> n >> tq;

    int *AT = new int[n];
    int *Flag = new int[n];
    int *inQ = new int[n];
    int *BT = new int[n];
    int *P = new int[n];
    int *CT = new int[n];
    int rp = n;
    for (t = 0; t < n; t++)
    {
        cin >> P[t] >> AT[t] >> BT[t];
        Flag[t] = 0;
        inQ[t] = 0;
        btSum += BT[t];
    }

    int track = AT[getMinTrack(AT, n)];
    // exit(0);
    while (btSum > 0)
    {
        pushQueueElements(n, Flag, inQ, track, AT);

        if (toPush)
        {
            pushQ(q[front - 1]);
            toPush = 0;
        }

        int cur = q[front];
        front++;
        if (BT[cur] > tq)
        {
            track += tq;
            inQ[cur] = 1;
            btSum -= tq;
            BT[cur] -= tq;
            inQ[cur] = 1;
        }
        else
        {
            rp--;
            track += BT[cur];
            btSum -= BT[cur];
            CT[cur] = track;
            Flag[cur] = 1;
            inQ[cur] = 0;
            BT[cur] = BT[cur] - BT[cur];
        }
        if (BT[q[front - 1]] > 0)
        {
            toPush = 1;
            inQ[q[front - 1]] = 1;
        }
        cout << track << " ";
    }
}
