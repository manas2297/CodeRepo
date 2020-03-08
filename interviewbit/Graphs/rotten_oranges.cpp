int Solution::solve(vector<vector<int>> &A)
{
  int n = A.size();
  int m = A[0].size();
  int t = 1;
  int one = 0;
  int count = 0;

  queue<pair<int, int>> q;
  for (int i = 0; i < A.size(); i++)
  {
    for (int j = 0; j < A[0].size(); j++)
    {
      if (A[i][j] == 2)
      {
        q.push(make_pair(i, j));
      }
    }
  }
  while (!q.empty())
  {
    int s = q.size();
    count = 0;
    while (s--)
    {
      pair<int, int> p = q.front();
      q.pop();
      int R[4] = {0, 1, -1, 0};
      int C[4] = {1, 0, 0, -1};
      for (int i = 0; i < 4; i++)
      {
        int x = R[i] + p.first;
        int y = C[i] + p.second;
        if ((x >= 0 && x < n) && (y >= 0 && y < m) && A[x][y] == 1)
        {
          A[x][y] = 2;
          q.push(make_pair(x, y));
        }
      }
    }
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (A[i][j] == 1)
        {
          count++;
        }
      }
    }
    if (count != 0)
    {
      t++;
    }
    if (count == 0)
    {
      break;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (A[i][j] == 1)
        one++;
    }
  }
  if (one != 0)
    return -1;
  else
    return t;
}
