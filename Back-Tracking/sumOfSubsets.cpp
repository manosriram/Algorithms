#include <iostream>
#include <vector>
using namespace std;
int n = 6, m = 30, sum = 0;
vector<int> v;

bool isSubsetSum(int currentSum, int remainingSum, int in) {
    if (currentSum == m)
        return true;

    if (in > (n - 1) || currentSum > m)
        return false;

    return (isSubsetSum(currentSum + v[in], remainingSum - v[in], in + 1) || isSubsetSum(currentSum, remainingSum - v[in], in + 1));
}

int main() {
    v.__emplace_back(5);
    v.__emplace_back(10);
    v.__emplace_back(12);
    v.__emplace_back(13);
    v.__emplace_back(15);
    v.__emplace_back(18);

    for (auto t : v)
        sum += t;

    cout << isSubsetSum(0, sum, 0) << endl;
}