#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *dp = new int[3*(n+1)];
    dp[1] = 0;
    for(int i=2;i<=3*(n+1);i++) {
        dp[i] = 1000000;
    }
    for(int i=1; i<=n; i++) {
        dp[i+1] = min(dp[i+1],dp[i] + 1);
        dp[2*i] = min(dp[2*i],dp[i] + 1);
        dp[3*i] = min(dp[3*i],dp[i] + 1);
    }

    cout << dp[n];

    return 0;
}