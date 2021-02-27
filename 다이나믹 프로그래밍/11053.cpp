#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max_value = 0;
    int *dp = new int[n+1];
    int *array = new int[n+1];

    for(int i=1;i<=n;i++) {
        cin >> array[i];
    }
    for(int i=1;i<=n;i++) {
        dp[i] = 1;
        for(int j=1;j<i;j++) {
            if(array[j] < array[i] && dp[j] + 1 > dp[i])
                dp[i]++;
        }
        max_value = max(max_value, dp[i]);
    }

    cout << max_value;

    delete[] dp;
    delete[] array;
    dp = NULL;
    array = NULL;
    return 0;
}