#include <iostream>
using namespace std;

int main() {
    int n, temp;
    int max = 0;
    cin >> n;
    int *dp = new int[n+1];
    int *array = new int[n+1];
    
    for(int i=1; i<=n; i++) {
        cin >> array[i];
        dp[i] = 1;
        for(int j=1; j<=i; j++) {
            if(array[i] < array[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        max = max > dp[i] ? max : dp[i];
    }

    cout << max;
    
    delete[] dp;
    delete[] array;
    array = NULL;
    dp = NULL;
    return 0;
}