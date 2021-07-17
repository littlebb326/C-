#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int map[50][50];
bool visit[50][50];
bool selected[10];
vector<pair<int, int>> pos;
vector<pair<int, int>> selected_pos;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int ans = 987654321;

bool check()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1)
                continue;
            if (!visit[i][j])
                return false;
        }
    }
    return true;
}
void spread()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < selected_pos.size(); i++)
    {
        int r = selected_pos[i].first;
        int c = selected_pos[i].second;
        q.push(make_pair(r, c));
        visit[r][c] = true;
    }
    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int next_r = r + dir[j][0];
                int next_c = c + dir[j][1];
                if (next_r >= 0 && next_c >= 0 && next_r < n && next_c < n)
                {
                    if (!visit[next_r][next_c] && map[next_r][next_c] != 1)
                    {
                        visit[next_r][next_c] = true;
                        q.push(make_pair(next_r, next_c));
                    }
                }
            }
        }
        if (q.size() != 0)
            time++;
    }
    if (check())
        ans = min(ans, time);
}
void find_pos(int idx, int cnt)
{
    if (cnt == m)
    {
        memset(visit, false, sizeof(visit));
        spread();
        return;
    }

    for (int i = idx; i < pos.size(); i++)
    {
        if (selected[i])
            continue;
        selected[i] = true;
        selected_pos.push_back(pos[i]);
        find_pos(i, cnt + 1);
        selected_pos.pop_back();
        selected[i] = false;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                pos.push_back(make_pair(i, j));
        }
    }

    find_pos(0, 0);
    if (ans == 987654321)
        ans = -1;
    cout << ans << endl;

    return 0;
}