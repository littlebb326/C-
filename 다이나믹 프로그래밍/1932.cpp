#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    int answer = 0;
    cin >> n;
    int **dp = new int*[n];
    for(int i=0; i<n; i++)
        dp[i] = new int[n];

    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cin >> dp[i][j];
        }
    }



    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            if(j == 0)
                dp[i][j] += dp[i-1][j];
            else if(j == i)
                dp[i][j] += dp[i-1][j-1];
            else
                dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
        }        
    }

    for(int i=0; i<n; i++) {
        answer = answer > dp[n-1][i] ? answer : dp[n-1][i];
    }

    cout << answer;

    for(int i=0; i<n; i++)
        delete[] dp[i];
    delete[] dp;
    return 0;
}