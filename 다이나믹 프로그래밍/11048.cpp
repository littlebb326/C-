#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int **dp = new int *[n];
    for(int i=0; i<n; i++) {
        dp[i] = new int[m];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int temp;
            cin >> temp;
            if(i == 0 && j == 0)
                dp[i][j] = temp;
            else if(i == 0)
                dp[i][j] = dp[i][j-1] + temp;
            else if(j == 0)
                dp[i][j] = dp[i-1][j] + temp;
            else
                dp[i][j] = max(max(dp[i-1][j-1], dp[i-1][j]),dp[i][j-1]) + temp;
        }
    }

    cout << dp[n-1][m-1];

    for(int i=0; i<n; i++)
        delete[] dp[i];
    delete[] dp;

    return 0;
}