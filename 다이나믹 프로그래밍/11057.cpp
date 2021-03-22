#include <iostream>
using namespace std;
int main() {
    int n;
    int dp[1001][11] = {0};
    cin >> n;

    for(int i=0;i<10;i++)
        dp[1][i] = 1;
    dp[1][10] = 10;

    for(int i=2;i<=n;i++) {
        int sum = 1;
        dp[i][0] = 1;
        for(int j=1;j<=9;j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007;
            sum += dp[i][j];
        }
        dp[i][10] = sum % 10007;
    }

    cout << dp[n][10];

    return 0;
}