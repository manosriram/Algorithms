#include <iostream>
using namespace std;
int ct = 0;

void Ways(int sum, int target) {
    if (sum == target) {
        ct++;
        return;
    }

    if (sum + 1 <= target)
        Ways(sum + 1, target);

    if (sum + 2 <= target)
        Ways(sum + 2, target);

    if (sum + 3 <= target)
        Ways(sum + 3, target);
}

int main() {
    int n = 3;

    Ways(0, n);
    cout << ct << endl;
}
