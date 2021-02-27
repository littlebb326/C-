#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long *dp = new long long[n+1];
    dp[1] = 1;
    dp[2] = 1;

    for(int i=3;i<=n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];

    delete[] dp;
    dp = NULL;
    return 0;
}