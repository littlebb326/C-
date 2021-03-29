#include <iostream>
#include <algorithm>
using namespace std;
int dp[101][100001];
int main()
{
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    int w, v;
    cin >> w >> v;
    for (int j = 1; j <= k; j++)
    {
      if (w > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j - w] + v, dp[i - 1][j]);
    }
  }

  cout << dp[n][k];

  return 0;
}