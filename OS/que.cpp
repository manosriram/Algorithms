#include <iostream>
#define MAX 100
using namespace std;

int front = -1;
int rear = -1;
int q[MAX];

void insertQ(int data)
{
    if (rear >= MAX)
    {
        cout << "Queue Overflow!!" << endl;
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    q[rear] = data;
}

int getTrack(int AT[], int n)
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
    int n, t, i;
    int track;
    cin >> n;
    int *AT = new int[n];
    int *P = new int[n];
    int *Flag = new int[n];
    int *BT = new int[n];
    int *inQ = new int[n];

    for (t = 0; t < n; t++)
    {
        cin >> P[t] >> AT[t] >> BT[t];
        Flag[t] = 0;
        inQ[t] = 0;
    }
    track = AT[getTrack(AT, n)];
    cout << track << endl;

    for (t = 0; t < n; t++)
    {
        if (Flag[t])
        {
            if (AT[t] <= track)
            {
                insertQ(P[t]);
            }
        }
    }

    for (t = front; t <= rear; t++)
        cout << q[t] << " ";
}