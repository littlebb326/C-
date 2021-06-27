#include <iostream>
using namespace std;
double chance[4];
bool visit[30][30];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
double total_chance = 0;
int n;

void dfs(int r, int c, double per)
{
    if (n == 0)
    {
        total_chance += per;
        return;
    }

    visit[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        int next_r = r + dir[i][0];
        int next_c = c + dir[i][1];

        if (!visit[next_r][next_c])
        {
            n--;
            dfs(next_r, next_c, per * chance[i]);
            n++;
            visit[next_r][next_c] = false;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        cin >> chance[i];
        chance[i] *= 0.01;
    }

    dfs(15, 15, 1.0);

    printf("%.10f", total_chance);

    return 0;
}