#include <iostream>
using namespace std;
int board[10][10];

void print() {
    for (int t=0;t<9;++t) {
        for (int j=0;j<9;++j) {
            cout << board[t][j] << " ";
        }
        cout << endl;
    }
}

bool isBoardFilled(int &t, int &j) {
    for (t=0;t<9;++t) {
        for (j=0;j<9;++j) {
            if (!board[t][j]) return false;
        }
    }
    return true;
}

bool isSafe(int r, int c, int v) {
    for (int t=0;t<9;++t)
        if (board[r][t] == v) return false;

    for (int t=0;t<9;++t)
        if (board[t][c] == v) return false;

    r = r - (r % 3);
    c = c - (c % 3);
    for (int t=0;t<3;++t) {
        for (int j=0;j<3;++j) {
            if (board[t + r][j + c] == v) return false;
        }
    }
    return true;
}

bool Solve() {
    int r, c;
    if (isBoardFilled(r, c)) return true;

    for (int t=1;t<10;++t) {
        if (isSafe(r, c, t)) {
            board[r][c] = t;
            if (Solve()) return true;
            board[r][c] = 0;
        }
    }
    return false;
}

int main() {
    Solve(); 
    print();
}
