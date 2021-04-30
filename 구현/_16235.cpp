#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int add[11][11];
int nut[11][11];
int eight_dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
vector<int> tree[11][11];
vector<int> die[11][11];
void spring()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      vector<int> temp;
      sort(tree[i][j].begin(), tree[i][j].end());
      for (int k = 0; k < tree[i][j].size(); k++)
      {
        //cout << "tree " << k << " : " << tree[i][j][k] << " / nut : " << nut[i][j] << endl;
        if (tree[i][j][k] <= nut[i][j]) // 양분 있는 경우
        {
          nut[i][j] -= tree[i][j][k];
          temp.push_back(tree[i][j][k] + 1);
        }
        else
        {
          die[i][j].push_back(tree[i][j][k]);
        }
      }
      tree[i][j].clear();
      tree[i][j] = temp;
    }
  }
}
void summer()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 0; k < die[i][j].size(); k++)
      {
        //cout << "die " << k << " at (" << i << ", " << j << ")" << endl;
        nut[i][j] += die[i][j][k] / 2;
      }
      die[i][j].clear();
    }
  }
}
void fall()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 0; k < tree[i][j].size(); k++)
      {
        if (tree[i][j][k] % 5 == 0)
        {
          for (int l = 0; l < 8; l++)
          {
            int next_r = i + eight_dir[l][0];
            int next_c = j + eight_dir[l][1];
            if (next_r > 0 && next_c > 0 && next_r <= n && next_c <= n)
              tree[next_r][next_c].push_back(1);
          }
        }
      }
    }
  }
}
void winter()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      nut[i][j] += add[i][j];
    }
  }
}
void four_season()
{
  spring();
  summer();
  fall();
  winter();
}
int main()
{
  int tree_cnt = 0;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> add[i][j];
      nut[i][j] = 5;
    }
  }

  for (int i = 0; i < m; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    tree[y][x].push_back(z);
  }

  for (int i = 0; i < k; i++)
  {
    four_season();
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      tree_cnt += tree[i][j].size();
    }
  }

  cout << tree_cnt;
  return 0;
}