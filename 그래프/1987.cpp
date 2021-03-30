#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 21
int r, c;
int max_count = 0;
int temp_count = 0;
char map[MAX][MAX];
bool visit[MAX][MAX];
bool alphabet_visit[26];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int char_to_idx(char alphabet)
{
  return ((int)alphabet - 65);
}
void DFS(int temp_r, int temp_c)
{
  visit[temp_r][temp_c] = true;
  alphabet_visit[char_to_idx(map[temp_r][temp_c])] = true;
  temp_count++;

  for (int i = 0; i < 4; i++)
  {
    int next_r = temp_r + dir[i][0];
    int next_c = temp_c + dir[i][1];
    if (next_r < 1 || next_r > r || next_c < 1 || next_c > c)
      continue;
    else if (!visit[next_r][next_c] && !alphabet_visit[char_to_idx(map[next_r][next_c])])
      DFS(next_r, next_c);
  }
  max_count = max(temp_count, max_count);
  visit[temp_r][temp_c] = false;
  alphabet_visit[char_to_idx(map[temp_r][temp_c])] = false;
  temp_count--;
}
int main()
{
  cin >> r >> c;
  for (int i = 1; i <= r; i++)
  {
    for (int j = 1; j <= c; j++)
    {
      cin >> map[i][j];
    }
  }
  DFS(1, 1);
  cout << max_count;

  return 0;
}