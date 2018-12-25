#include <iostream>
using namespace std;

int btSum(int BT[], int n)
{
    int sum = 0;
    int k;

    for (k = 0; k < n; k++)
    {
        sum += BT[k];
    }
    return sum;
}

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

int main()
{
    int n, t;
    int track, btAdd;

    cin >> n;

    int *CT = new int[n];
    int *AT = new int[n];
    int *BT = new int[n];
    int *WT = new int[n];
    int *RT = new int[n];
    int *TAT = new int[n];
    int *check = new int[n];
    int *Flag = new int[n];
    int *P = new int[n];
    int *BT1 = new int[n];

    for (t = 0; t < n; t++)
    {
        cin >> P[t] >> AT[t] >> BT[t];
        Flag[t] = 0;
        check[t] = 0;
        BT1[t] = BT[t];
        btAdd += BT[t];
    }
    track = getMinTrack(AT, n);
    // btAdd = btSum(BT, n);

    int i, j, min, ind;

    for (i = track; i <= btAdd; i++)
    {
        min = INT_MAX;
        for (j = 0; j < n; j++)
        {
            if (!Flag[j])
            {
                if (AT[j] <= i)
                {
                    if (BT[j] < min)
                    {
                        min = BT[j];
                        ind = j;
                    }
                }
            }
        }
        if (BT[ind] > 0)
        {
            BT[ind] -= 1;
            if (check[ind] == 0)
            {
                check[ind] = i;
            }
        }

        if (!BT[ind])
        {
            Flag[ind] = 1;
            CT[ind] = i + 1;
        }
    }

    int wtSum = 0, tatSum = 0;
    for (t = 0; t < n; t++)
    {
        RT[t] = check[t] - AT[t];
        TAT[t] = CT[t] - AT[t];
        WT[t] = TAT[t] - BT1[t];
        wtSum += WT[t];
        tatSum += TAT[t];
    }

    for (t = 0; t < n; t++)
    {
        cout << P[t] << '\t' << AT[t] << "\t" << BT1[t] << "\t" << CT[t] << '\t' << WT[t] << '\t' << RT[t] << '\t' << TAT[t] << endl;
    }
}