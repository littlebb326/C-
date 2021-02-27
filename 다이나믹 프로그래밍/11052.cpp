#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;
    int *dp = new int[n+1];

    for(int i=1; i<n+1; i++) {
        cin >> dp[i];
        for(int j=1; j<=i/2; j++) {
            dp[i] = max(dp[j] + dp[i-j],dp[i]);
        }
    }

    cout << dp[n];

    delete[] dp;
    dp = NULL;
    return 0;
}