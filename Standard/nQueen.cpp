#include <bits/stdc++.h>
using namespace std;

bool showSteps = true; // Flag to control step-by-step trace

bool isSafe(int row, int col, vector<string>& board, int n) {
    int orig_row = row, orig_col = col;

    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row--; col--;
    }

    row = orig_row; col = orig_col;
    while (col >= 0) {
        if (board[row][col] == 'Q') return false;
        col--;
    }

    row = orig_row; col = orig_col;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') return false;
        row++; col--;
    }

    return true;
}

void printBoard(const vector<string>& board) {
    for (const string& row : board) {
        cout << row << "\n";
    }
    cout << "-------------------\n";
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (col == n) {
        ans.push_back(board);
        showSteps = false; // After first solution, disable step-by-step tracing
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';

            if (showSteps) {
                cout << "Placed Q at (" << row << ", " << col << "):\n";
                printBoard(board);
            }

            solve(col + 1, board, ans, n);

            board[row][col] = '.';

            if (showSteps) {
                cout << "Backtracking from (" << row << ", " << col << "):\n";
                printBoard(board);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter board size (n): ";
    if (!(cin >> n)) {
        cout << "Invalid input! Please enter a valid integer.\n";
        return 1;
    }

    if (n <= 0) {
        cout << "Board size must be positive.\n";
        return 1;
    }

    if (n == 2 || n == 3) {
        cout << "No solutions exist for n = " << n << ".\n";
        return 0;
    }

    if (n > 15) {
        cout << "Warning: Large board size, may take a long time.\n";
    }

    
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    solve(0, board, ans, n);

    cout << "\n=== All Solutions ===\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << "\n";
        }
        cout << "\n";
    }

    return 0;
}