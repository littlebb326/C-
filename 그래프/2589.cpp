#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge
{
    int r, c, cost;
    Edge(int _r, int _c, int _cost)
    {
        r = _r;
        c = _c;
        cost = _cost;
    }
};

char map[51][51];
bool visit[51][51][2];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            visit[i][j][1] = false;
        }
    }
}
int bfs(int r, int c)
{
    init();
    queue<Edge> q;
    int max_cost = 0;
    q.push(Edge(r, c, 0));
    visit[r][c][1] = true;
    while (!q.empty())
    {
        Edge e = q.front();
        q.pop();
        max_cost = max(max_cost, e.cost);
        for (int i = 0; i < 4; i++)
        {
            int next_r = e.r + dir[i][0];
            int next_c = e.c + dir[i][1];
            if (next_r > 0 && next_c > 0 && next_r <= n && next_c <= m)
            {
                if (!visit[next_r][next_c][1] && map[next_r][next_c] == 'L')
                {
                    visit[next_r][next_c][1] = true;
                    q.push(Edge(next_r, next_c, e.cost + 1));
                }
            }
        }
    }
    return max_cost;
}
int main()
{
    int answer = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visit[i][j][0] && map[i][j] == 'L')
            {
                visit[i][j][0] = true;
                answer = max(bfs(i, j), answer);
            }
        }
    }
    cout << answer;
    return 0;
}