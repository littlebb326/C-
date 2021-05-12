#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001][2];
int main()
{
    int n;
    cin >> n;
    cin >> dp[1][0] >> dp[2][0];
    dp[1][1] = dp[1][0];
    dp[2][1] = dp[1][0] + dp[2][0];

    for (int i = 3; i <= n; i++)
    {
        cin >> dp[i][0];
        dp[i][1] = dp[i][0] + max(dp[i - 2][1], (dp[i - 3][1] + dp[i - 1][0]));
        dp[i][1] = max(dp[i][1], dp[i - 1][1]);
    }

    cout << dp[n][1];

    return 0;
}