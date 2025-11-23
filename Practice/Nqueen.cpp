#include <bits/stdc++.h>
using namespace std;
bool showsteps = true;

bool issafe(int row, int col, vector<string> &board, int n)
{
  int nrow = row;
  int ncol = col;
  while (row >= 0 && col >= 0)
  {
    if (board[row][col] == 'Q')
    {
      return false;
    }
    row--;
    col--;
  }
  int row1 = nrow;
  int col1 = ncol;
  while (row1 < n && col1 >= 0)
  {
    if (board[row1][col1] == 'Q')
    {
      return false;
    }
    row1++;
    col1--;
  }

  row = nrow;
  col = ncol;
  while (col >= 0) {
    if (board[row][col] == 'Q') return false;
    col--;
  }
  return true;
}
void printboard(vector<string>&board)
{
  for (string &row : board)
  {
    cout << row << endl;
  }
  cout << "------------------" << endl;
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
  if (col == n)
  {
    ans.push_back(board);
    showsteps = false;
    return;
  }
  for (int row = 0; row < n; row++)
  {
    if (issafe(row, col, board, n))
    {

      board[row][col] = 'Q';
      if (showsteps)
      {
        cout << "Q is placed at (" << row << "," << col << ") in the board" << endl;
        printboard(board);
      }
      solve(col + 1, board, ans, n);
      board[row][col] = '.';
      if (showsteps)
      {
        cout << "Backtracking from (" << row << "," << col << ") in the board" << endl;
        printboard(board);
      }
    }
  }
}

int main()
{
  int n;
  cout << "Enter the number of queens:";

  if (!(cin >> n))
  {
    cout << "Please enter the vaild input" << endl;
    return 1;
  }
  if (n <= 0)
  {
    cout << "Please enter a positivr integer greater than zero" << endl;
    return 1;
  }
  if (n == 2 || n == 3)
  {
    cout << "Solutions does not exists for the given value...\n";
    return 0;
  }
  if (n > 15)
  {
    cout << "To many large value...\n";
  }
  vector<vector<string>> ans;
  vector<string> board(n, string(n, '.'));

  solve(0, board, ans, n);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << "=====Solution: " << i + 1 << "=====" << endl;
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << endl;
    }
    cout << endl;
  }
  return 0;
}