
vector<vector<int>> Solution::solve(vector<vector<int>> &A)
{
  int n = A.size();
  int m = A[0].size();
  int r[] = {0, 1, -1, 0};
  int l[] = {-1, 0, 0, 1};
  queue<pair<int, int>> q;
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (A[i][j] == 1)
      {
        dist[i][j] = 0;
        q.push(make_pair(i, j));
      }
    }
  }
  pair<int, int> p;
  while (!q.empty())
  {
    p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    for (int k = 0; k < 4; k++)
    {
      int adx = x + r[k];
      int ady = y + l[k];
      if (adx >= 0 && adx < n && ady >= 0 && ady < m && (dist[adx][ady] > dist[x][y] + 1))
      {
        dist[adx][ady] = dist[x][y] + 1;
        q.push(make_pair(adx, ady));
      }
    }
  }
  return dist;
}
