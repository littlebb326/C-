#include <iostream>
using namespace std;
int n;
int map[101][101];
long long dp[101][101];

long long dfs(int r, int c) {
    if(r == n && c ==n)
        return 1;
    else if(dp[r][c] == -1) {
        dp[r][c] = 0;
        if(map[r][c] + r <= n) {
            dp[r][c] += dfs(map[r][c]+r,c);
        }
        if(map[r][c] + c <= n) {
            dp[r][c] += dfs(r, map[r][c] + c);
        }
    }
    return dp[r][c];
}
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    cout << dfs(1,1);        
}