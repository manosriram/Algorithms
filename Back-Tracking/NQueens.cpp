#include <iostream>
#include <vector>
#define N 4
using namespace std;

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

bool isSafeMove(int board[N][N], int r, int c) {
    int i, j;
    for (int t = 0; t < c; t++)
        if (board[r][t])
            return false;

    i = r, j = c;
    while ((i >= 0) && (j >= 0)) {
        if (board[i][j])
            return false;

        --i;
        --j;
    }

    i = r, j = c;
    while ((i < N) && (j >= 0)) {
        if (board[i][j])
            return false;

        ++i;
        --j;
    }
    return true;
}

bool Solve(int board[N][N], int col) {
    if (col >= N)
        return true;

    for (int t = 0; t < N; t++) {
        if (isSafeMove(board, t, col)) {
            board[t][col] = 1;

            if (Solve(board, col + 1))
                return true;

            board[t][col] = 0;
        }
    }
    return false;
}

void showPossibleLegalPostitions() {
    int board[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    if (!Solve(board, 0)) {
        cout << "Not Possible." << '\n';
        return;
    }

    printBoard(board);
    return;
}

int main() {
    showPossibleLegalPostitions();
}