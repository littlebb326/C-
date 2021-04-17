#include <iostream>
using namespace std;
int main() {
    int n;
    int max = 0;
    int box[1001];
    int dp[1001];
    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> box[i];
        dp[i] = 1;
    }

    for(int i=1;i<=n;i++) {
        for(int j=0;j<i;j++) {
            if(box[j] < box[i] && (dp[j] + 1) > dp[i])
                dp[i]++;
        }
        max = max > dp[i] ? max : dp[i];
    }

    cout << max;

    return 0;
}