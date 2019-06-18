#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<
        vector<int>

        >
        v;

    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    vector<int> temp2;
    temp2.push_back(10);
    temp2.push_back(2);
    temp2.push_back(3123);

    v.push_back(temp);
    v.push_back(temp2);

    for (int t = 0; t < 2; t++)
    {
        sort(v[t].begin(), v[t].end());
        for (auto i = v[t].begin(); i != v[t].end(); i++)
            cout << *i << " ";
    }
}