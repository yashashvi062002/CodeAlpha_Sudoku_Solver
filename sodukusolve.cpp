#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>>& board, int R, int C, int NUM) {
    // Check the row
    for (int i = 0; i < 9; i++) {
        if (board[R][i] == NUM) return false;
    }

    // Check the column
    for (int i = 0; i < 9; i++) {
        if (board[i][C] == NUM) return false;
    }

    // Check the 3x3 box
    int bRow = R - R % 3;
    int bCol = C - C % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[bRow + i][bCol + j] == NUM) return false;
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                for (int NUM = 1; NUM <= 9; NUM++) {
                    if (isValid(board, i, j, NUM)) {
                        board[i][j] = NUM;
                        if (solveSudoku(board)) return true;
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board(9, vector<int>(9));

    cout << "Enter the Sudoku value" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    if (solveSudoku(board)) {
        cout << "Solved Sudoku:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
