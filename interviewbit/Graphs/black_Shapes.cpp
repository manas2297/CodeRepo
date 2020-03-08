vector<string> v;
void DFS(int i, int j)
{
  if (i < 0 || i >= v.size() || j < 0 || j >= v[i].size())
  {
    return;
  }
  if (v[i][j] != 'X')
    return;
  v[i][j] = '0';
  DFS(i + 1, j);
  DFS(i - 1, j);
  DFS(i, j + 1);
  DFS(i, j - 1);
}
int Solution::black(vector<string> &A)
{
  v = A;
  int r = 0;
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v[i].size(); j++)
    {
      if (v[i][j] == 'X')
      {
        DFS(i, j);
        r++;
      }
    }
  }
  return r;
}
