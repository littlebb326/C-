#include <iostream>
#include <queue>
using namespace std;
#define SPACE 0
#define CHEESE 1
#define AIR 2

int n, m;
int time = 0;
int cheese_cnt = 0;
int map[101][101];
int adj[101][101];
bool visit[101][101];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            visit[i][j] = false;
            adj[i][j] = 0;
        }
    }
}
void bfs_adj(int r, int c)
{
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    visit[r][c] = true;
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_r = temp.first + dir[i][0];
            int next_c = temp.second + dir[i][1];
            if (next_r > 0 && next_c > 0 && next_c <= m && next_r <= n)
            {
                if (map[next_r][next_c] == AIR)
                    adj[temp.first][temp.second]++;
                else if (!visit[next_r][next_c] && map[next_r][next_c] == CHEESE)
                {
                    visit[next_r][next_c] = true;
                    q.push(make_pair(next_r, next_c));
                }
            }
        }
    }
}
void find_adj()
{
    init();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visit[i][j] && map[i][j] == 1)
            {
                bfs_adj(i, j);
            }
        }
    }
}
void bfs_air(int r, int c)
{
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    visit[r][c] = true;
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        map[temp.first][temp.second] = AIR;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_r = temp.first + dir[i][0];
            int next_c = temp.second + dir[i][1];
            if (next_r > 0 && next_c > 0 && next_c <= m && next_r <= n)
            {
                if (!visit[next_r][next_c] && map[next_r][next_c] != CHEESE)
                {
                    visit[next_r][next_c] = true;
                    q.push(make_pair(next_r, next_c));
                }
            }
        }
    }
}
void find_air()
{
    init();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 || j == 1 || i == n || i == m)
            {
                if (map[i][j] != CHEESE)
                    bfs_air(i, j);
            }
        }
    }
}
void melt_cheese()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (adj[i][j] >= 2)
            {
                map[i][j] = 2;
                cheese_cnt--;
            }
        }
    }
}
void solve()
{
    time++;
    find_air();
    find_adj();
    melt_cheese();
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                cheese_cnt++;
        }
    }

    while (cheese_cnt > 0)
        solve();
    cout << time;

    return 0;
}