// n queens
// yash rajput
// 19 march 2022

#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}
bool solveNQ(vector<vector<int>> &board, int col) {
    int n = board.size();
    if (col >= n)
        return 1;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQ(board, col + 1)) {
                return 1;
            }
            board[i][col] = 0;
        }
    }
    return 0;
}
int main() {
    int n;
    cout << "Enter the size of board\n";
    cin >> n;
    vector<vector<int>> board;
    for (int i = 0; i < n; i++) {
        vector<int> tem;
        for (int j = 0; j < n; j++) {
            tem.push_back(0);
        }
        board.push_back(tem);
    }

    if (!solveNQ(board, 0))
        cout << "No possible solution exist\n";
    else {
        cout << "One of the possible solution is: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
    cout << "\n";
    cout << "\n";
}