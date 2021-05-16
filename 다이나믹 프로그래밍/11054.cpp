#include <iostream>
using namespace std;

int dp[1001][2];
int array[1001];
int n;

int main()
{
    int max_val = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> array[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;

        for (int j = 1; j < i; j++)
        {
            if (array[j] < array[i] && dp[j][0] + 1 > dp[i][0])
                dp[i][0]++;
        }
    }

    for (int i = n; i >= 1; i--)
    {
        dp[i][1] = 1;
        for (int j = n; j > i; j--)
        {
            if (array[j] < array[i] && dp[j][1] + 1 > dp[i][1])
                dp[i][1]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int temp = dp[i][0] + dp[i][1];
        //cout << i << " : " << dp[i][0] << ", " << dp[i][1] << endl;
        max_val = max_val > temp ? max_val : temp;
    }
    cout << max_val - 1;

    return 0;
}