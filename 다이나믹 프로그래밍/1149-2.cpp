#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];
int main()
{
  int n, answer;
  cin >> n;
  cin >> dp[1][0] >> dp[1][1] >> dp[1][2];
  for (int i = 2; i <= n; i++)
  {
    int r, g, b;
    cin >> r >> g >> b;
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r;
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g;
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b;
  }

  answer = min(min(dp[n][0], dp[n][1]), dp[n][2]);
  cout << answer;

  return 0;
}