#include <iostream>
using namespace std;
int n, m;
int water[51][51];
int cloud[51][51];
bool is_rain[51][51];
pair<int, int> move_arr[101];
int eight_dir[9][2] = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int four_dir[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int move_cnt = 1;
void move_cloud()
{
    int new_cloud[51][51] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cloud[i][j] == 1) // cloud exist
            {
                pair<int, int> p = move_arr[move_cnt];
                int move_r = eight_dir[p.first][0] * p.second;
                int move_c = eight_dir[p.first][1] * p.second;

                int next_r = (move_r % n) + i;
                if (next_r <= 0)
                    next_r += n;
                else if (next_r > n)
                    next_r = next_r % n;

                int next_c = (move_c % n) + j;
                if (next_c <= 0)
                    next_c += n;
                else if (next_c > n)
                    next_c = next_c % n;

                new_cloud[next_r][next_c] = 1;
            }
        }
    }

    //cout << "###print cloud###" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cloud[i][j] = new_cloud[i][j];
            //cout << new_cloud[i][j] << ' ';
        }
        //cout << endl;
    }
}
void rain()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cloud[i][j] == 1)
            {
                water[i][j]++;
                is_rain[i][j] = true;
            }
        }
    }
}
void remove_cloud()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cloud[i][j] == 1)
                cloud[i][j] = -1;
        }
    }
}
void duplicate_water()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (is_rain[i][j])
            {
                is_rain[i][j] = false;
                for (int k = 0; k < 4; k++)
                {
                    int next_r = i + four_dir[k][0];
                    int next_c = j + four_dir[k][1];

                    if (next_r > 0 && next_c > 0 && next_r <= n && next_c <= n)
                    {
                        if (water[next_r][next_c] > 0)
                            water[i][j]++;
                    }
                }
            }
        }
    }
}
void make_cloud()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (cloud[i][j] == -1) // is_removed_cloud
                cloud[i][j] = 0;
            else if (water[i][j] >= 2)
            {
                cloud[i][j] = 1;
                water[i][j] -= 2;
            }
        }
    }
}
int get_water()
{
    int total_water = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            total_water += water[i][j];
        }
    }
    return total_water;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> water[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        move_arr[i] = make_pair(a, b);
    }

    cloud[n][1] = 1;
    cloud[n][2] = 1;
    cloud[n - 1][1] = 1;
    cloud[n - 1][2] = 1;

    while (move_cnt <= m)
    {
        move_cloud();
        rain();
        remove_cloud();
        duplicate_water();
        make_cloud();
        move_cnt++;
    }

    cout << get_water();

    return 0;
}