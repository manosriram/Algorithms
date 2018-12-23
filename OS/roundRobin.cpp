#include <iostream>
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
    }
    return min;
}

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
                    }
                }
            }
        }

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

}