#include <iostream>
#include <string.h>
using namespace std;

string isPal(string st)
{
    int a = 0, b = st.length() - 1;
    while (a < b)
    {
        char temp = st[a];
        st[a] = st[b];
        st[b] = temp;
        a++;
        b--;
    }
    return st;
}

int main()
{
    int T;
    cin >> T;
    char st[100];
    string st1[100];
    int ind = 0;
    while (T--)
    {
        cin >> st;
        st1[ind] = st;
        ind++;
    }
    for (int t = 0; t < ind; t++)
    {
        string temp = st1[t];
        for (int j = t + 1; j < ind; j++)
        {
            string temp1 = isPal(st1[j]);
            if (temp == temp1)
            {
                cout << temp.length() << " " << temp[temp.length() / 2] << endl;
                break;
            }
        }
    }
}