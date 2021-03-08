#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int max_val;
    int dp[100001];
    cin >> n;
    cin >> dp[1];
    max_val = dp[1];
    for(int i=2;i<=n;i++) {
        int temp;
        cin >> temp;
        dp[i] = max(dp[i-1] + temp, temp);
        max_val = max(max_val, dp[i]);
    }
    cout << max_val;

    return 0;
}