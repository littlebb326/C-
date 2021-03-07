#include <iostream>
using namespace std;
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int tg_x, tg_y;
int tg_dir, dir;
void get_left_target()
{
    if (dir == NORTH)
    {
        tg_y--;
        tg_dir = WEST;
    }
    else if (dir == EAST)
    {
        tg_x--;
        tg_dir = NORTH;
    }
    else if (dir == SOUTH)
    {
        tg_y++;
        tg_dir = EAST;
    }
    else if (dir == WEST)
    {
        tg_x++;
        tg_dir = SOUTH;
    }
}
void go_back()
{
    if (dir == NORTH)
    {
        tg_x++;
    }
    else if (dir == EAST)
    {
        tg_y--;
    }
    else if (dir == SOUTH)
    {
        tg_x--;
    }
    else if (dir == WEST)
    {
        tg_y++;
    }
}
int main()
{
    int n, m;
    int x, y;
    int clean_cnt = 0;
    int find_cnt = 0;
    cin >> n >> m;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];
    cin >> x >> y >> dir;
    tg_x = x;
    tg_y = y;
    tg_dir = dir;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    while (1)
    {
        //cout << "x : " << x << ' ' << "y : " << y << ' ' << "dir : " << dir << ' ' << "find_cnt : " << find_cnt << endl;
        if (arr[x][y] == 0)
        {
            arr[x][y] = 2;
            clean_cnt++;
        }
        get_left_target();
        if (arr[tg_x][tg_y] == 0)
        {
            find_cnt = 0;
            x = tg_x;
            y = tg_y;
            dir = tg_dir;
            continue;
        }
        else if (arr[tg_x][tg_y] == 1 || arr[tg_x][tg_y] == 2)
        {
            if (find_cnt == 4)
            {
                tg_x = x;
                tg_y = y;
                tg_dir = dir;
                go_back();
                if (arr[tg_x][tg_y] == 1)
                {
                    break;
                }
                x = tg_x;
                y = tg_y;
                find_cnt = 0;
                continue;
            }
            find_cnt++;
            tg_x = x;
            tg_y = y;
            dir = tg_dir;
            continue;
        }
    }
    cout << clean_cnt;
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}