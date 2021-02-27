#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int result = 0;
    cin >> n;
    int **dp = new int*[n+6]();
    for(int i=0;i<n+6;i++) {
        dp[i] = new int[3]();
    }

    for(int i=1;i<=n;i++) {
        int max_money = 0;
        cin >> dp[i][0] >> dp[i][1];
        for(int j=1;j<i;j++) {
            max_money = max_money > dp[j][2] ? max_money : dp[j][2];
        }
        dp[i + dp[i][0] -1][2] = max(max_money + dp[i][1], dp[i + dp[i][0] -1][2]);
    }

    for(int i=1;i<=n;i++)
        result = result > dp[i][2] ? result : dp[i][2];

    cout << result;

    for(int i=0;i<n+1;i++)
        delete[] dp[i];
    delete[] dp;
    dp = NULL;
    return 0;
}