#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n, ans1, ans2;
    int min = 2000000001;
    vector<int> sol_v;
    int left = 0;
    int right;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sol_v.push_back(temp);
    }

    sort(sol_v.begin(), sol_v.end());
    right = n - 1;
    while (left < right)
    {
        int sum = sol_v[left] + sol_v[right];
        int abs_sum = abs(sum);
        if (abs_sum <= min)
        {
            ans1 = sol_v[left];
            ans2 = sol_v[right];
            min = abs_sum;
        }
        if (sum > 0)
            right--;
        else
            left++;
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}