#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[101][101];
bool visit[101][101];
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int r, c;
int cheese_cnt = 0;
vector<int> cheese_cnt_v;
void find_melting_area(int start_r, int start_c)
{
  queue<pair<int, int>> q;
  q.push(make_pair(start_r, start_c));
  visit[start_r][start_c] = true;

  while (!q.empty())
  {
    int temp_r = q.front().first;
    int temp_c = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int next_r = temp_r + direction[i][0];
      int next_c = temp_c + direction[i][1];
      if (next_r > 0 && next_r <= r && next_c > 0 && next_c <= c)
      {
        if (map[next_r][next_c] == 1)
          map[next_r][next_c] = 2;
        else if (!visit[next_r][next_c] && map[next_r][next_c] == 0)
        {
          q.push(make_pair(next_r, next_c));
          visit[next_r][next_c] = true;
        }
      }
    }
  }
}
void remove_melted_cheese()
{
  for (int i = 1; i <= r; i++)
  {
    for (int j = 1; j <= c; j++)
    {
      if (map[i][j] == 2)
      {
        map[i][j] = 0;
        cheese_cnt--;
      }
    }
  }
}
void visit_map_init()
{
  for (int i = 1; i <= r; i++)
  {
    for (int j = 1; j <= c; j++)
    {
      visit[i][j] = false;
    }
  }
}
void melt_cheese()
{
  visit_map_init();
  for (int i = 1; i <= r; i++)
  {
    for (int j = 1; j <= c; j++)
    {
      if (i == 1 || i == r || j == 1 || j == c)
      {
        find_melting_area(i, j);
      }
    }
  }
}
void print_map()
{
  for (int i = 1; i <= r; i++)
  {
    for (int j = 1; j <= c; j++)
    {
      cout << map[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}
int main()
{
  int time = 0;
  cin >> r >> c;

  for (int i = 1; i <= r; i++)
  {
    for (int j = 1; j <= c; j++)
    {
      cin >> map[i][j];
      if (map[i][j] == 1)
        cheese_cnt++;
    }
  }
  cheese_cnt_v.push_back(cheese_cnt);
  while (cheese_cnt > 0)
  {
    melt_cheese();
    remove_melted_cheese();
    cheese_cnt_v.push_back(cheese_cnt);
  }
  time = cheese_cnt_v.size() - 1;
  cout << time << endl;
  cout << cheese_cnt_v[time - 1];

  return 0;
}