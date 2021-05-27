#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int ans_move = 0;

int get_pin(char map[5][9])
{
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (map[i][j] == 'o')
                cnt++;
        }
    }
    return cnt;
}
void solve(char map[5][9], int count)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (map[i][j] == 'o')
            {
                for (int k = 0; k < 4; k++)
                {
                    int next_r = i + dir[k][0];
                    int next_c = j + dir[k][1];

                    if (next_r < 0 || next_r >= 5 || next_c < 0 || next_c >= 9)
                        continue;

                    if (map[next_r][next_c] == 'o')
                    {
                        int next_r2 = next_r + dir[k][0];
                        int next_c2 = next_c + dir[k][1];

                        if (next_r2 < 0 || next_r2 >= 5 || next_c2 < 0 || next_c2 >= 9)
                            continue;

                        if (map[next_r2][next_c2] == '.')
                        {
                            char next_map[5][9];
                            copy(&map[0][0], &map[0][0] + 45, &next_map[0][0]);
                            next_map[next_r][next_c] = '.';
                            next_map[i][j] = '.';
                            next_map[next_r2][next_c2] = 'o';
                            solve(next_map, count + 1);
                        }
                    }
                }
            }
        }
    }

    if (count > ans_move)
        ans_move = count;
}
int main()
{
    cin >> n;

    for (int test = 0; test < n; test++)
    {
        char map[5][9];
        int pin_cnt;
        ans_move = 0;

        for (int i = 0; i < 5; i++)
        {
            cin >> map[i];
        }
        pin_cnt = get_pin(map);
        solve(map, 0);
        pin_cnt -= ans_move;

        cout << pin_cnt << ' ' << ans_move << endl;
    }
    return 0;
}