#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[501][501];
int main()
{
    cin >> n;
    cin >> dp[1][1];
    int answer = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> dp[i][j];
            dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
        answer = answer > dp[n][i] ? answer : dp[n][i];

    cout << answer;
    return 0;
}