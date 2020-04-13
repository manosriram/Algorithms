#include <iostream>
using namespace std;
int board[9][9] = { { 0 } };
bool visited[9][9] = { { false } };
int moves[2][9] = { { 2, 1, -1, -2, -2, -1, 1, 2 }, { 1, 2, 2, 1, -1, -2, -2, -1 } };

bool safe(int r, int c) {
    return (r >= 0 && r < 8 && c >= 0 && c < 8 && !board[r][c]);
}

void print() {
    for (int t=0;t<8;++t) {
        for (int j=0;j<8;++j) {
            cout << board[t][j] << " ";
        }
        cout << endl;
    }
}

bool Solve(int r, int c, int in) {
    if (in == 64) return true;

    for (int t=0;t<8;++t) {
        int rr = r + moves[0][t], cc = c + moves[1][t];
        if (safe(rr, cc)) {
            board[rr][cc] = in;
            if (Solve(rr, cc, in+1)) return true;
            else board[rr][cc] = 0;
        }
    }
    return false;
}

int main() {
   Solve(0, 0, 1); 
   print();
}
