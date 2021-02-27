#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int result = 99999;
    cin >> n;
    int dp[1000][3] = {
        0,
    };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> dp[i][j];
        }
        dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
    }

    for (int i = 0; i < 3; i++)
    {
        result = dp[n][i] < result ? dp[n][i] : result;
    }

    cout << result;

    return 0;
}