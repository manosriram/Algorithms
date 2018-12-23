#include <iostream>
using namespace std;

int q[100];
int n, i, j;

int rear = -1;
int front = -1;

void deleter()
{
    if (front == -1 || front > rear)
    {
        return;
    }
    else
    {
        front = front + 1;
    }
}

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

void display()
{
    int i;
    if (front == -1)
        cout << "Queue Empty.." << endl;
    else
    {
        for (i = front; i <= rear; i++)
        {
            cout << q[i] << " ";
        }
    }
}

int btAdd(int BT[], int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += BT[i];
    }
    return sum;
}

int leastAT(int AT[], int n)
{
    int i, min = AT[0], ind;
    for (i = 0; i < n; i++)
    {
        if (AT[i] < min)
        {
            min = AT[i];
            ind = i;
        }
    }
    return ind;
}

int main()
{
    int n, timeQuantum;
    cin >> n >> timeQuantum;

    int *AT = new int[n];
    int *Flag = new int[n];
    int *count = new int[1000];
    int *P = new int[n];
    int *BT = new int[n];
    int *store = new int[100];

    int j, t;

    for (t = 0; t < n; t++)
    {
        cin >> P[t] >> AT[t] >> BT[t];
        Flag[t] = 0;
        store[t] = -1;
    }

    int btSum = btAdd(BT, n);
    int getAT = leastAT(AT, n);
    int track = AT[getAT];
    int current = -1;
    int flag = 0;
    int cur;
    int i = 0;
    int cnt1 = 0;
    int cnt = 0;
    int rem = 0;

    while (btSum > 0)
    {
        if (front == -1)
        {
            insert(P[getAT]);
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                if (!Flag[i])
                {
                    for (j = 0; j < cnt1; j++)
                    {
                        if (P[i] != store[j])
                        {
                            if (AT[i] <= track)
                            {
                                insert(P[i]);
                            }
                        }
                    }
                }
            }
        }
        if (cnt1 > 0)
        {
            for (t = 0; t < cnt1; t++)
            {
                insert(store[t]);
                store[t] = -1;
            }
            cnt1 = 0;
        }

        for (t = front; t <= rear; t++)
        {
            cur = q[t];
            if (BT[cur - 1] > timeQuantum)
            {
                track += timeQuantum;

                count[cnt] = track;
                cnt++;

                btSum -= timeQuantum;
                BT[cur - 1] -= timeQuantum;
                Flag[cur - 1] = 0;
            }
            else
            {
                track += BT[cur - 1];

                count[cnt] = track;
                cnt++;

                btSum -= BT[cur - 1];
                BT[cur - 1] = 0;
                Flag[cur - 1] = 1;
            }
            if (BT[cur - 1] > 0)
            {
                store[cnt1] = P[cur - 1];
                cnt1++;
            }
            front++;
        }
    }

    for (t = 0; t < cnt; t++)
        cout << count[t] << " ";
}