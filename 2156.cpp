#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    int dp[10001] = {0,};
    int array[10001] = {0,};
    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> array[i];
    }

    dp[1] = array[1];
    dp[2] = array[1] + array[2];

    for(int i=3;i<=n;i++) {
        dp[i] = max(dp[i-3] + array[i-1] + array[i], dp[i-2] + array[i]);
        dp[i] = max(dp[i], dp[i-1]);
    }

    cout << dp[n];

    return 0;
}