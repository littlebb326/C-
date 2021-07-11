#include <iostream>
#include <algorithm>
using namespace std;
int dp[4001][4001];
int main()
{
    string s1;
    string s2;

    cin >> s1 >> s2;

    int ans = 0;

    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans;

    return 0;
}