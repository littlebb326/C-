#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, T;
    cin >> T;

    int dp[2][100001] = {
        0,
    };
    int array[2][100001] = {
        0,
    };

    for (int i = 0; i < T; i++)
    {
        cin >> n;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= n; j++)
                cin >> array[i][j];
        }

        dp[0][1] = array[0][1];
        dp[1][1] = array[1][1];

        for (int i = 2; i <= n; i++)
        {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + array[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + array[1][i];
        }

        cout << max(dp[0][n], dp[1][n]) << endl;
    }
    return 0;
}