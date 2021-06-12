#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, q;
int main_size;
vector<int> level;
vector<int> ice;
int map[65][65];
int adj_map[65][65];
bool visit[65][65];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs(int r, int c)
{
    int ice_cnt = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    visit[r][c] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_r = p.first + dir[i][0];
            int next_c = p.second + dir[i][1];
            if (next_r <= 0 || next_c <= 0 || next_r > main_size || next_c > main_size)
                continue;
            if (!visit[next_r][next_c] && map[next_r][next_c] > 0)
            {
                q.push(make_pair(next_r, next_c));
                visit[next_r][next_c] = true;
                ice_cnt++;
            }
        }
    }
    return ice_cnt;
}
int get_biggest_ice()
{
    int biggest = 0;
    for (int i = 1; i <= main_size; i++)
    {
        for (int j = 1; j <= main_size; j++)
        {
            if (!visit[i][j] && map[i][j] > 0)
            {
                ice.push_back(bfs(i, j));
            }
        }
    }
    if (!ice.empty())
    {
        sort(ice.begin(), ice.end(), greater<>());
        biggest = ice[0];
    }
    return biggest;
}
int get_total_ice()
{
    int total = 0;
    for (int i = 1; i <= main_size; i++)
    {
        for (int j = 1; j <= main_size; j++)
        {
            total += map[i][j];
        }
    }
    return total;
}
void reduce()
{
    for (int i = 1; i <= main_size; i++)
    {
        for (int j = 1; j <= main_size; j++)
        {
            int adj_cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int next_r = i + dir[k][0];
                int next_c = j + dir[k][1];
                if (next_r <= 0 || next_c <= 0 || next_r > main_size || next_c > main_size)
                    continue;
                if (map[next_r][next_c] > 0)
                    adj_cnt++;
            }
            adj_map[i][j] = adj_cnt;
        }
    }

    for (int i = 1; i <= main_size; i++)
    {
        for (int j = 1; j <= main_size; j++)
        {
            if (adj_map[i][j] < 3 && map[i][j] > 0)
                map[i][j]--;
        }
    }
}
void rotate(int sub_size, int r, int c)
{
    vector<int> sub_v;
    int idx = 0;
    for (int j = c; j < c + sub_size; j++)
    {
        for (int i = r + sub_size - 1; i >= r; i--)
        {
            sub_v.push_back(map[i][j]);
        }
    }

    for (int i = r; i < r + sub_size; i++)
    {
        for (int j = c; j < c + sub_size; j++)
        {
            map[i][j] = sub_v[idx];
            idx++;
        }
    }
}
void firestorm(int l)
{
    int sub_size = (int)pow(2, l);
    int sub_cnt = (int)(main_size / sub_size);
    int r = 1;
    int c = 1;
    if (sub_size > 1)
    {
        for (int i = 1; i < main_size; i += sub_size)
        {
            for (int j = 1; j < main_size; j += sub_size)
            {
                rotate(sub_size, i, j);
            }
        }
    }
    reduce();
}
int main()
{
    cin >> n >> q;
    main_size = (int)pow(2, n);
    for (int i = 1; i <= main_size; i++)
    {
        for (int j = 1; j <= main_size; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < q; i++)
    {
        int l;
        cin >> l;
        level.push_back(l);
    }

    for (int i = 0; i < level.size(); i++)
    {
        firestorm(level[i]);
    }
    cout << get_total_ice() << endl;
    cout << get_biggest_ice();
    return 0;
}