#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dice[10001][6];
int ans = 0;
int sum = 0;

void find_max(int temp_dice_num, int prev_top_val)
{
    if (temp_dice_num == n)
    {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        if (dice[temp_dice_num][i] != prev_top_val)
            continue;
        int temp_max = -1;
        int reverse_idx = (i + 3) % 6;
        for (int j = 0; j < 6; j++)
        {
            if (j == i || j == reverse_idx)
                continue;
            else
            {
                temp_max = max(temp_max, dice[temp_dice_num][j]);
            }
        }
        sum += temp_max;
        find_max(temp_dice_num + 1, dice[temp_dice_num][reverse_idx]);
        sum -= temp_max;
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dice[i][0] >> dice[i][1] >> dice[i][2] >> dice[i][4] >> dice[i][5] >> dice[i][3];
    }

    for (int i = 0; i < 6; i++)
    {
        find_max(0, dice[0][i]);
    }

    cout << ans;
    return 0;
}