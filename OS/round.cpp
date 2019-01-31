#include <iostream>
using namespace std;

int getMinTrack(int AT[], int n)
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

int *queue = new int[300];
int main()
{

    int n, tq;
    cin >> n >> tq;
    int t, i, j, next = -1;
    int *AT = new int[n];
    int *BT = new int[n];
    int *BT1 = new int[n];
    int *CT = new int[n];
    int *Flag = new int[n];
    int *inQ = new int[n];
    int *P = new int[n];
    int *WT = new int[n];
    int *TAT = new int[n];
    float AWT, ATAT;
    float sumWT = 0, sumTAT = 0;
    int front = 0, rear = -1;
    int sum = 0, cur = -1;
    int remain = n;
    int tobeIns = -1;
    for (t = 0; t < n; t++)
    {
        cin >> P[t] >> AT[t] >> BT[t];
        BT1[t] = BT[t];
        sum += BT[t];
        Flag[t] = 0;
        inQ[t] = 0;
    }

    int track = getMinTrack(AT, n);

    while (1)
    {
        for (t = 0; t < n; t++)
        {
            if (AT[t] <= track && tobeIns != t && !Flag[t] && !inQ[t])
            {
                rear++;
                queue[rear] = t;
                inQ[t] = 1;
            }
        }
        if (tobeIns != -1)
        {
            rear++;
            queue[rear] = tobeIns;
        }

        cur = queue[front];
        front++;

        if (BT[cur] > tq)
        {
            track += tq;
            sum -= tq;
            BT[cur] -= tq;
        }
        else
        {
            track += BT[cur];
            sum -= BT[cur];
            BT[cur] -= BT[cur];
            CT[cur] = track;
            Flag[cur] = 1;
        }

        if (BT[cur] > 0)
        {
            tobeIns = cur;
        }
        else
        {
            tobeIns = -1;
        }
        if (sum <= 0)
            break;
    }

    for (t = 0; t < n; t++)
    {
        TAT[t] = CT[t] - AT[t];
        WT[t] = TAT[t] - BT1[t];
        sumWT += WT[t];
        sumTAT += TAT[t];
    }
    AWT = sumWT / n;
    ATAT = sumTAT / n;

    cout << "ProcessID" << '\t' << "A.T" << '\t' << "B.T" << '\t' << "C.T" << '\t' << "T.A.T" << '\t' << "W.T" << '\n';
    for (t = 0; t < n; t++)
    {
        cout << P[t] << '\t' << '\t' << AT[t] << '\t' << BT1[t] << '\t' << CT[t] << '\t' << TAT[t] << '\t' << WT[t] << '\n';
    }
    cout << "Average Waiting Time : " << AWT << '\n';
    cout << "Average Turn-Around-Time : " << ATAT << '\n';
}