/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/
class Solution {
    int n = 3, N = 9;
    int rows[9][10] = {}, cols[9][10] = {}, boxes[9][10] = {};
    vector<vector<char>>* boardPtr;
    bool sudokuSolved = false;

    bool couldPlace(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        return rows[row][d] + cols[col][d] + boxes[idx][d] == 0;
    }

    void placeNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]++;
        cols[col][d]++;
        boxes[idx][d]++;
        (*boardPtr)[row][col] = d + '0';
    }

    void removeNumber(int d, int row, int col) {
        int idx = (row / n) * n + col / n;
        rows[row][d]--;
        cols[col][d]--;
        boxes[idx][d]--;
        (*boardPtr)[row][col] = '.';
    }

    void placeNextNumbers(int row, int col) {
        if (row == N - 1 && col == N - 1) sudokuSolved = true;
        else if (col == N - 1) backtrack(row + 1, 0);
        else backtrack(row, col + 1);
    }

    void backtrack(int row, int col) {
        if ((*boardPtr)[row][col] == '.') {
            for (int d = 1; d <= 9; d++) {
                if (couldPlace(d, row, col)) {
                    placeNumber(d, row, col);
                    placeNextNumbers(row, col);
                    if (!sudokuSolved) removeNumber(d, row, col);
                }
            }
        } else placeNextNumbers(row, col);
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        boardPtr = &board;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] != '.') placeNumber(board[i][j] - '0', i, j);
        backtrack(0, 0);
    }
};