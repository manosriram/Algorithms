#include <iostream>
using namespace std;

int main()
{
    int ind, loopInd, itr, flag, N, j;
    int T;
    cin >> T;
    while (T--)
    {
        flag = 0;
        cin >> N;
        int *a = new int[N];
        for (j = 0; j < N; j++)
            cin >> a[j];
        loopInd = N - 1;
        ind = -1;
        itr = 0;
        while (!flag)
        {
            if (itr % 2 == 0)
            {
                if (ind == -2 || loopInd == 0)
                {
                    cout << "Ashish" << '\n';
                    break;
                }
                else
                {
                    for (j = loopInd; j > 0; j--)
                    {
                        if (a[j - 1] < a[j])
                        {
                            ind = j - 1;
                            itr++;
                            loopInd = ind;
                            break;
                        }
                        else
                        {
                            ind = -2;
                            break;
                        }
                    }
                }
            }
            else
            {
                if (ind == -2 || loopInd == 0)
                {
                    cout << "Jeel" << '\n';
                    break;
                }
                else
                {
                    for (j = loopInd; j > 0; j--)
                    {
                        if (a[j - 1] < a[j])
                        {
                            ind = j - 1;
                            itr++;
                            loopInd = ind;
                            break;
                        }
                        else
                        {
                            ind = -2;
                            break;
                        }
                    }
                }
            }
        }
    }
}