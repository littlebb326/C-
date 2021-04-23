#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> arr[501];
bool visit[501];
queue<pair<int, int>> friend_q;

int main()
{
  int n, m;
  int a, b;
  int friend_cnt = 0;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }

  friend_q.push(make_pair(1, 0));
  visit[1] = true;

  while (!friend_q.empty())
  {
    int temp = friend_q.front().first;
    int temp_depth = friend_q.front().second;
    friend_q.pop();
    if (temp_depth >= 2)
      continue;

    for (int i = 0; i < arr[temp].size(); i++)
    {
      int next = arr[temp][i];
      if (!visit[next])
      {
        visit[next] = true;
        friend_q.push(make_pair(next, temp_depth + 1));
        friend_cnt++;
      }
    }
  }

  cout << friend_cnt;

  return 0;
}