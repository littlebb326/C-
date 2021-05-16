#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Block_group
{
    int size, rainbow;
    pair<int, int> standard;
    vector<pair<int, int>> block_v;
};

int map[21][21];
bool visit[21][21];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
int score = 0;
vector<Block_group> v;

bool compare(Block_group b1, Block_group b2)
{
    if (b1.size != b2.size)
        return b1.size > b2.size;
    else if (b1.rainbow != b2.rainbow)
        return b1.rainbow > b2.rainbow;
    else if (b1.standard.first != b2.standard.first)
        return b1.standard.first > b2.standard.first;
    else
        return b1.standard.second > b2.standard.second;
}
void init_visit()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            visit[i][j] = false;
}
void init_vector()
{
    v.clear();
}
void bfs(int r, int c, int target)
{
    Block_group bg;
    int size = 0;
    int rainbow = 0;
    queue<pair<int, int>> q;
    visit[r][c] = true;
    q.push(make_pair(r, c));
    bg.standard = make_pair(r, c);

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        bg.block_v.push_back(p);
        q.pop();
        size++;

        for (int i = 0; i < 4; i++)
        {
            int next_r = p.first + dir[i][0];
            int next_c = p.second + dir[i][1];
            if (next_r > 0 && next_c > 0 && next_r <= n && next_c <= n && !visit[next_r][next_c])
            {
                if (map[next_r][next_c] == -1 || map[next_r][next_c] == -2)
                    continue;
                else if (map[next_r][next_c] == 0)
                {
                    rainbow++;
                    visit[next_r][next_c] = true;
                    q.push(make_pair(next_r, next_c));
                }
                else if (map[next_r][next_c] == target)
                {
                    visit[next_r][next_c] = true;
                    q.push(make_pair(next_r, next_c));
                }
            }
        }
    }
    bg.size = size;
    bg.rainbow = rainbow;
    if (size >= 2)
    {
        v.push_back(bg);
    }
}
void find_group()
{
    init_vector();
    for (int i = 1; i <= m; i++)
    {
        init_visit();
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (!visit[j][k] && map[j][k] == i)
                    bfs(j, k, i);
            }
        }
    }
}
void remove_block()
{
    Block_group bg = v[0];
    int size = bg.block_v.size();
    score += size * size;
    for (int i = 0; i < bg.block_v.size(); i++)
    {
        map[bg.block_v[i].first][bg.block_v[i].second] = -2;
    }
}
void print()
{
    cout << "######## map ########" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}
void gravity()
{
    for (int j = 1; j <= n; j++) // 열
    {
        int idx = n;
        for (int i = n; i > 0; i--)
        {
            if (map[i][j] == -2)
                continue;
            else if (map[i][j] == -1)
            {
                idx = i - 1;
            }
            else
            {
                int temp = map[i][j];
                map[i][j] = -2;
                map[idx][j] = temp;
                idx--;
            }
        }
    }
}
void rotate()
{
    int temp_map[21][21] = {0};
    vector<int> v;
    int idx = 0;
    for (int j = n; j > 0; j--)
    {
        for (int i = 1; i <= n; i++)
        {
            v.push_back(map[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = v[idx];
            idx++;
        }
    }
}
int main()
{
    cin >> n >> m;
    bool is_finish = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }

    while (!is_finish)
    {
        find_group();
        if (v.size() == 0)
        {
            is_finish = true;
            continue;
        }
        sort(v.begin(), v.end(), compare);
        remove_block();
        gravity();
        rotate();
        gravity();
    }
    cout << score;

    return 0;
}