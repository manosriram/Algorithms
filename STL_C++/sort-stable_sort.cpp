#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> ss = {"mouse", "dog", "cat", "ant", "moth", "elephant"};

    // Lambda Function which can be used to sort by length.
    auto sortByLength = [](const auto &a, const auto &b) { return a.size() < b.size(); };

    sort(ss.begin(), ss.end(), sortByLength);
    for (auto t : ss)
        cout << t << " ";

    cout << endl;
}