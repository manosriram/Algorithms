#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <limits.h>
#define trace(x) cerr << #x << " " << x << '\n';
#define ld long long
#define disp(n) for (auto t : n)
#define forn(t, n) for (ld t = 0; t < n; t++)
#define pb push_back
#define mod 1000000007
#define c_sort(a) sort(a, a + sizeof(a) / sizeof(a[0]))
#define NL cout << '\n';
#define INF (int)1e9
using namespace std;
typedef vector<int> vI;
int max_, min_;

void displayBuckets(vector<string> ob[], vector<string> eb[])
{
    cout << "Odd Bucket" << endl;
    for (int k = 0; k < 10; k++)
    {
        cout << "Bucket " << k << " : ";
        disp(ob[k])
        {
            cout << t << " ";
        }
        NL;
    }
    NL;
    cout << "Even Bucket" << endl;
    for (int k = 0; k < 10; k++)
    {
        cout << "Bucket " << k << " : ";
        disp(eb[k])
        {
            cout << t << " ";
        }
        NL;
    }
    NL;
    return;
}

void selectGL(string n)
{
    if (n == "000")
    {
        max_ = 0;
        min_ = 0;
        return;
    }
    for (int t = 0; t < int(n.length()); t++)
    {
        if (int(n[t] - '0') > max_)
            max_ = n[t] - '0';
        if (int(n[t] - '0') < min_)
            min_ = n[t] - '0';
    }
    return;
}

int getSignificantBit(string n)
{
    int a = n[0] - '0';
    return a;
}

string removeSignificantBit(int n)
{
    string temp = std::to_string(n);

    (temp.length() == 3) ? temp.erase(0, 1) : "";
    return temp;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int T, add_ = 0, sum_ = 0, level = 1;
    cin >> T;
    string n;
    vector<string> oddBucket[10], evenBucket[10];
    string ind_;
    if (T > 0 && T <= 500)
    {
        for (int t = 1; t <= T; t++)
        {
            max_ = INT_MIN, min_ = INT_MAX;
            cin >> n;
            if (n[0] == '-')
                n.erase(0, 1);
            selectGL(n);
            add_ = (max_ * 11) + (min_ * 7);
            ind_ = removeSignificantBit(add_);
            int buck = getSignificantBit(ind_);
            (t % 2 != 0) ? oddBucket[buck].push_back(ind_) : evenBucket[buck].push_back(ind_);
        }

        for (int k = 0; k < 10; k++)
        {
            sum_ += (oddBucket[k].size() > 2 ? 2 : oddBucket[k].size() == 2 ? 1 : 0);
            sum_ += (evenBucket[k].size() > 2 ? 2 : evenBucket[k].size() == 2 ? 1 : 0);
        }
        displayBuckets(oddBucket, evenBucket);
    }

    cout << sum_;
    return 0;
}