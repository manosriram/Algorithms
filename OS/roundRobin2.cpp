#include <iostream>
using namespace std;
int main()
{
    int wtime[10], btime[10], rtime[10], num, quantum, total;
    cout << "Enter number of processes(MAX 10): ";
    cin >> num;

    cout << "Enter burst time";
    for (int i = 0; i < num; i++)
    {
        cout << "\nP[" << i + 1 << "]: ";
        cin >> btime[i];
        rtime[i] = btime[i];
        wtime[i] = 0;
    }
    cout << "\n\nEnter quantum: ";
    cin >> quantum;
    int rp = num;
    int i = 0;
    int time = 0;
    cout << "0";
    wtime[0] = 0;
    while (rp != 0)
    {
        if (rtime[i] > quantum)
        {
            rtime[i] = rtime[i] - quantum;
            cout << " | P[" << i + 1 << "] | ";
            time += quantum;
            cout << time;
        }
        else
        {
            time += rtime[i];
            rtime[i] = rtime[i] - rtime[i];
            cout << " | P[" << i + 1 << "] | ";
            rp--;
            cout << time;
        }

        i++;
        if (i == num)
        {
            i = 0;
        }
    }
    system("pause");
    return 0;
}