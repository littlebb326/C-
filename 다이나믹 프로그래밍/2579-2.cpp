#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[301][2];
int main()
{
    cin >> n;
    cin >> dp[1][0];
    dp[1][1] = dp[1][0];
    cin >> dp[2][1];
    dp[2][0] = dp[2][1];
    dp[2][0] += dp[1][0];

    for (int i = 3; i <= n; i++)
    {
        cin >> dp[i][1];
        dp[i][0] = dp[i][1] + max(dp[i - 2][0], (dp[i - 3][0] + dp[i - 1][1]));
    }
    cout << dp[n][0];

    return 0;
}