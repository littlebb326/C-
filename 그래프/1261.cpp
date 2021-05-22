#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[101][101];
int wall_map[101][101];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Edge
{
    int r, c;

    Edge(int _r, int _c)
    {
        r = _r;
        c = _c;
    }
};
int main()
{
    queue<Edge> q;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = temp[j - 1] - '0';
        }
    }

    q.push(Edge(1, 1));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            wall_map[i][j] = 18181818;
        }
    }
    wall_map[1][1] = 0;

    while (!q.empty())
    {

        Edge e = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_r = e.r + dir[i][0];
            int next_c = e.c + dir[i][1];

            if (next_r > 0 && next_c > 0 && next_r <= m && next_c <= n)
            {
                if (map[next_r][next_c] == 1)
                {
                    if (wall_map[next_r][next_c] > wall_map[e.r][e.c] + 1)
                    {
                        q.push(Edge(next_r, next_c));
                        wall_map[next_r][next_c] = wall_map[e.r][e.c] + 1;
                    }
                }
                else
                {
                    if (wall_map[next_r][next_c] > wall_map[e.r][e.c])
                    {
                        q.push(Edge(next_r, next_c));
                        wall_map[next_r][next_c] = wall_map[e.r][e.c];
                    }
                }
            }
        }
    }

    cout << wall_map[m][n];

    return 0;
}