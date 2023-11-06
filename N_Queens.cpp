#include <iostream>
#include <vector>

using namespace std;

void solveNQueensUtil(vector<vector<int>>& board, vector<int>& cols, vector<int>& diag1, vector<int>& diag2, int row, int n) {
    if (row == n) {
        // Print the solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (cols[col] == 0 && diag1[row + col] == 0 && diag2[row - col + n - 1] == 0) {
            // Place the queen at this position
            board[row][col] = 1;
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 1;

            // Recursively place queens in the remaining rows
            solveNQueensUtil(board, cols, diag1, diag2, row + 1, n);

            // Backtrack and remove the queen from this position
            board[row][col] = 0;
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 0;
        }
    }
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> cols(n, 0);
    vector<int> diag1(2 * n - 1, 0);
    vector<int> diag2(2 * n - 1, 0);

    solveNQueensUtil(board, cols, diag1, diag2, 0, n);
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
