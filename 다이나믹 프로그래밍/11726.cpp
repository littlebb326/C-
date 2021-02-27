#include <iostream>
using namespace std;
int main() {
    int n, result;
    cin >> n;
    int *dp = new int[n+1]{};
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<=n;i++) {
        dp[i] = (dp[i-2] + dp[i-1]) % 10007;
    }

    result = dp[n];
    
    delete[] dp;
    dp = NULL;

    cout << result;
    return 0;
}