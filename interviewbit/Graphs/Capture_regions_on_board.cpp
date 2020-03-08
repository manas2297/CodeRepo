void check(vector<vector<char>> &A, int x, int y, char preV, char curV)
{
  int m = A.size();
  int n = A[0].size();
  if (x < 0 || x >= m || y < 0 || y >= n)
  {
    return;
  }
  if (A[x][y] != preV)
  {
    return;
  }
  A[x][y] = curV;

  check(A, x, y + 1, preV, curV);
  check(A, x + 1, y, preV, curV);
  check(A, x - 1, y, preV, curV);
  check(A, x, y - 1, preV, curV);
}
void Solution::solve(vector<vector<char>> &A)
{
  // Do not write main() function.
  // Do not read input, instead use the arguments to the function.
  // Do not print the output, instead return values as specified
  // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  int m = A.size();
  int n = A[0].size();

  if (m == n && m == 1)
  {
    return;
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // cout<<A[i][j]<<"..";
      if (A[i][j] == 'O')
      {

        A[i][j] = '-';
        // cout<<A[i][j]<<".....";
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    if (A[i][0] == '-')
      check(A, i, 0, '-', 'O');
  }
  for (int i = 0; i < n; i++)
  {
    if (A[0][i] == '-')
      check(A, 0, i, '-', 'O');
  }
  for (int i = 0; i < m; i++)
  {
    if (A[i][n - 1] == '-')
      check(A, i, n - 1, '-', 'O');
  }
  for (int i = 0; i < n; i++)
  {
    if (A[m - 1][i] == '-')
      check(A, m - 1, i, '-', 'O');
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (A[i][j] == '-')
        A[i][j] = 'X';
    }
  }
}
