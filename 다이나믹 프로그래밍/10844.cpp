#include <iostream>
using namespace std;
int main()
{
    int n;
    int dp[101][11];
    fill(&dp[0][0], &dp[100][11], 0);
    cin >> n;

    // for (int i = 0; i < 101; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    dp[1][10] = 9;
    for (int i = 1; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= 100; i++)
    {
        dp[i][0] = dp[i - 1][1] % 1000000000;
        dp[i][9] = dp[i - 1][8] % 1000000000;
        for (int j = 1; j <= 8; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
        dp[i][10] = ((dp[i - 1][10] * 2) - dp[i - 1][0] - dp[i - 1][9]) % 1000000000;
        if (dp[i][10] < 0)
            dp[i][10] += 1000000000;
    }

    cout << dp[n][10];

    return 0;
}