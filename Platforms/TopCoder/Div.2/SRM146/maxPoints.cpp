#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxPoints(vector<int> toss)
{
    sort(toss.begin(), toss.end() + 5);
    int ind = 4, sum = 0;

    while (toss[ind] == toss[ind - 1])
    {
        ind--;
        sum += toss[ind];
    }
    sum += toss[ind];
    return sum;
}

int main()
{
    vector<int> toss;
    int temp;
    for (int t = 0; t < 5; t++)
    {
        cin >> temp;
        toss.push_back(temp);
    }

    cout << maxPoints(toss) << endl;
}