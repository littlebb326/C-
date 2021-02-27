#include <iostream>
using namespace std;

int main() {

    int n;
    int *dp = new int[21];
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=20; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];

    delete[] dp;
    dp = NULL;
    return 0;
}