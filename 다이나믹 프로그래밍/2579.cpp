#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[301][3];

int main()
{
    int array[301]{0};
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> array[i];

    dp[2][1] = array[2];
    dp[1][1] = array[1];
    dp[2][2] = array[1] + array[2];

    for (int i = 3; i <= n; i++)
    {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + array[i];
        dp[i][2] = max(dp[i - 3][1], dp[i - 3][2]) + array[i - 1] + array[i];
    }

    cout << max(dp[n][1], dp[n][2]);
    return 0;
}