#include <iostream>
using namespace std;
int t;
int player_data[11][11];
bool select_arr[11];
int ans = 0;

void search(int selected, int sum)
{
    if (selected == 11)
    {
        ans = ans > sum ? ans : sum;
        return;
    }
    for (int i = 0; i < 11; i++)
    {
        if (player_data[selected][i] != 0 && !select_arr[i])
        {
            select_arr[i] = true;
            search(selected + 1, sum + player_data[selected][i]);
            select_arr[i] = false;
        }
    }
}
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ans = 0;
        for (int j = 0; j < 11; j++)
            for (int k = 0; k < 11; k++)
                cin >> player_data[j][k];
        for (int i = 0; i < 11; i++)
        {
            if (player_data[0][i] != 0)
            {
                select_arr[i] = true;
                search(1, player_data[0][i]);
                select_arr[i] = false;
            }
        }
        cout << ans << endl;
    }

    return 0;
}