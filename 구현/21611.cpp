#include <iostream>
#include <vector>
using namespace std;
int n, m;
int map[50][50];
int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int spiral_dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
vector<pair<int, int>> spiral;
vector<int> marble;
int shark_r;
int shark_c;
vector<pair<int, int>> magic;
int ans = 0;

void map_init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = 0;
        }
    }
}
void group()
{
    vector<int> temp_marble;
    for (int i = 0; i < marble.size(); i++)
    {
        int idx = i;
        int num = marble[i];
        while (marble[i] == marble[idx] && idx < marble.size())
            idx++;

        int count = idx - i;
        temp_marble.push_back(count);
        temp_marble.push_back(num);
        i = idx - 1;
    }
    map_init();
    int marble_cnt = temp_marble.size();
    for (int i = 0; i < spiral.size(); i++)
    {
        pair<int, int> p = spiral[i];
        if (i >= marble_cnt)
            map[p.first][p.second] = 0;
        else
            map[p.first][p.second] = temp_marble[i];
    }
}
void explode()
{
    bool is_exploded = true;
    while (is_exploded)
    {
        vector<int> temp_marble;
        is_exploded = false;
        for (int i = 0; i < marble.size(); i++)
        {
            int idx = i;
            while (marble[i] == marble[idx] && idx < marble.size())
                idx++;

            int count = idx - i;
            if (count >= 4)
            {
                is_exploded = true;
                ans += (marble[i] * count);
            }
            else
            {
                for (int j = i; j < idx; j++)
                {
                    temp_marble.push_back(marble[j]);
                }
            }
            i = idx - 1;
        }
        marble = temp_marble;
    }
}
void move_marble()
{
    marble.clear();
    for (int i = 0; i < spiral.size(); i++)
    {
        pair<int, int> p = spiral[i];
        if (map[p.first][p.second] != 0)
        {
            marble.push_back(map[p.first][p.second]);
        }
        map[p.first][p.second] = 0;
    }

    for (int i = 0; i < marble.size(); i++)
    {
        pair<int, int> p = spiral[i];
        map[p.first][p.second] = marble[i];
    }
}
void break_marble(int d, int s)
{
    for (int j = 1; j <= s; j++)
    {
        int break_r = shark_r + (dir[d][0] * j);
        int break_c = shark_c + (dir[d][1] * j);
        map[break_r][break_c] = 0;
    }
}
void blizzard(int magic_idx)
{
    int d = magic[magic_idx].first;
    int s = magic[magic_idx].second;
    break_marble(d, s);
    move_marble();
    explode();
    group();
}
void get_input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int d, s;
        cin >> d >> s;
        magic.push_back(make_pair(d, s));
    }

    shark_r = (n + 1) / 2;
    shark_c = shark_r;

    int r = shark_r;
    int c = shark_c;
    int idx = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 0; j < i; j++)
            {
                r += spiral_dir[idx][0];
                c += spiral_dir[idx][1];
                spiral.push_back(make_pair(r, c));
            }
            ++idx %= 4;
        }
    }
    for (int j = 0; j < n - 1; j++)
    {
        r += spiral_dir[idx][0];
        c += spiral_dir[idx][1];
        spiral.push_back(make_pair(r, c));
    }
}
int main()
{
    get_input();
    for (int i = 0; i < m; i++)
    {
        blizzard(i);
    }
    cout << ans;

    return 0;
}