void bfs(vector<vector<int>> &A, vector<vector<int>> &vis, int x, int y)
{
  int n = A.size();
  int m = A[0].size();
  vis[x][y] = 1;
  int r[] = {1, -1, 1, 1, -1, -1, 0, 0};
  int l[] = {0, 0, -1, 1, -1, 1, 1, -1};
  for (int k = 0; k < 8; k++)
  {
    int adx = x + r[k];
    int ady = y + l[k];
    if (adx >= 0 && adx < n && ady >= 0 && ady < m && A[adx][ady] == 1 && vis[adx][ady] == 0)
    {
      vis[adx][ady] = 1;
      bfs(A, vis, adx, ady);
    }
  }
}
int Solution::solve(vector<vector<int>> &A)
{
  int n = A.size();
  int m = A[0].size();
  queue<pair<int, int>> q;
  int r[] = {1, -1, 1, 1, -1, -1, 0, 0};
  int l[] = {0, 0, -1, 1, -1, 1, 1, -1};
  vector<vector<int>> vis(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (A[i][j] == 1)
      {
        q.push(make_pair(i, j));
      }
    }
  }
  pair<int, int> p;
  int count = 0;
  while (!q.empty())
  {
    p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    if (vis[x][y] != 1)
    {
      bfs(A, vis, x, y);
      count++;
    }
  }
  return count;
}
