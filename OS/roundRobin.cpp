#include <iostream>
<<<<<<< HEAD
#define maxQ 500
using namespace std;

int front=-1;
int rear = -1;
int q[maxQ];


void insert(int data) {

if (front==maxQ) {
    cout << "Max Overflow" << endl;
    return;
}

if (front==-1) front=0;

rear++;
q[rear] = data;

}

int getMinAt(int AT[], int n) {
    int k,min = AT[0];
    for (k=0;k<n;k++) {
        if (AT[k] < min) min = AT[k];
=======
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
>>>>>>> fc94caf21c8d5d9437ef8e713eebf493fad47015
    }
    return min;
}

<<<<<<< HEAD
int getBtSum(int BT[], int n) {
    int k,sum=0;
    for (k=0;k<n;k++) sum += BT[k];

    return sum;
}

int main() {
    int n, timeQuantum;
    int i,j,t;
    cin >> n >> timeQuantum;
    int *AT = new int[n+1];
    int *BT = new int[n+1];
    int *CT = new int[n+1];
    int *Flag = new int[n+1];
    int *P = new int[n+1];
    int *inQueue = new int[n+1];

    for (t=1;t<=n;t++) {
    cin >> P[t] >> AT[t] >> BT[t];
    Flag[t] = 0;
    inQueue[t] = 0;
    }

    int track = getMinAt(AT,n);
    int btSum = getBtSum(BT,n);

    while (btSum > 0) {

        for (t=1;t<=n;t++) {
            if (!Flag[t]) {
                if (!inQueue[t]) {
                    if (AT[t] <= track) {
                        insert(P[t]);
                        inQueue[t] = 1;
=======
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
    btAdd = btSum(BT, n);
    int track = leastAT(AT, n);
    int completedCount = 1;

    while (btAdd > 0)
    {
        for (i = 0; i < n; i++)
        {
            if (!Flag[i])
            {
                if (!Completed[i])
                {
                    if (AT[i] <= track)
                    {
                        insert(P[i]);
>>>>>>> fc94caf21c8d5d9437ef8e713eebf493fad47015
                    }
                }
            }
        }

<<<<<<< HEAD
        int cur = q[front];
        if (BT[cur] > timeQuantum) {
            track += timeQuantum;
            btSum -= timeQuantum;
            BT[cur] -= timeQuantum;
        } else {
            track += BT[cur];
            btSum -= BT[cur];
            BT[cur] = 0;
            Flag[cur]=0;
            inQueue[cur] = 0;
        }

        for (t=1;t<=n;t++) {
            if (!Flag[t]) {
                if (!inQueue[t]) {
                    if (AT[t] <= track) {
                        insert(P[t]);
                        inQueue[t] = 1;
                    }
                }
            }
        }

        if (BT[cur] > 0) {
            inQueue[cur] = 1;
            insert(P[cur]);
        }
        front++;
        cout << track << " ";
    }

=======
        for (int k = 1; k < n; k++)
        {
            for (t = 0; t < n; t++)
            {
                if (Completed[t] == k)
                {
                    insert(P[t]);
                    Completed[t] = 0;
                }
            }
        }
        completedCount = 1;

        for (t = front; t <= rear; t++)
        {
            cur = q[t];

            if (BT[cur - 1] > timeQuantum)
            {
                track += timeQuantum;
                btAdd -= timeQuantum;
                BT[cur - 1] -= timeQuantum;
            }
            else
            {
                track += BT[cur - 1];
                CT[cur - 1] = track;
                btAdd -= BT[cur - 1];
                BT[cur - 1] = 0;
                Flag[cur - 1] = 1;
            }
            if (BT[cur - 1] > 0)
            {
                Completed[cur - 1] = completedCount;
                completedCount++;
            }

            front++;
            // cnt++;
            // cout << track << " ";
        }
    }
    float wtSum = 0, tatSum = 0;
    for (t = 0; t < n; t++)
    {
        TAT[t] = CT[t] - AT[t];
        WT[t] = TAT[t] - BT1[t];
        tatSum += TAT[t];
        wtSum += WT[t];
    }
    float AWT, ATAT;

    AWT = wtSum / n;
    ATAT = tatSum / n;

    front = 0;
    for (t = 0; t < n; t++)
        cout << CT[t] << " ";

    // cout << AWT << " " << ATAT << endl;
>>>>>>> fc94caf21c8d5d9437ef8e713eebf493fad47015
}
