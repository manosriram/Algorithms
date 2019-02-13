#include <iostream>
using namespace std;

void wait(int &n)
{
    if (n > 0)
        n--;
}

void signal(int &n)
{
    n++;
}

int main()
{
    int *buffer = new int[10];
    static int empty = 10, full = 0;
    static int mutex = 1;
    int ch;
    while (1)
    {
        cout << "Empty : " << empty << " Full : " << full << " Mutex : " << mutex << endl;
        cout << "1.Produce \n2.Consume \n3.Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (empty != 0 && mutex == 1)
            {
                wait(empty);
                wait(mutex);
                cin >> buffer[full];
                signal(mutex);
                signal(full);
            }
            else
                cout << "Buffer Full..Please Consume.." << endl;
            break;
        case 2:
            if (full > 0 && mutex == 1)
            {
                wait(full);
                wait(mutex);
                cout << "Removed : " << buffer[full] << endl;
                signal(mutex);
                signal(empty);
            }
            else
                cout << "Buffer Empty .. Please Produce.." << endl;
            break;
        case 3:
            exit(0);
        }
    }
}