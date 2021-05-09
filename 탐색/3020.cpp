#include <iostream>
#include <algorithm>
using namespace std;
int arr1[100000];
int arr2[100000];
int n, h;
int min_val = 200001;
int min_cnt = 0;
int main()
{
    cin >> n >> h;
    for (int i = 0; i < n / 2; i++)
    {
        cin >> arr1[i] >> arr2[i];
    }
    sort(arr1, arr1 + (n / 2));
    sort(arr2, arr2 + (n / 2));

    for (int i = 1; i <= h; i++)
    {
        int cnt = lower_bound(arr1, arr1 + (n / 2), i) - arr1;
        cnt += upper_bound(arr2, arr2 + (n / 2), h - i) - arr2;
        cnt = n - cnt;

        if (min_val == cnt)
        {
            min_cnt++;
        }
        else if (min_val > cnt)
        {
            min_cnt = 1;
            min_val = cnt;
        }
    }

    cout << min_val << ' ' << min_cnt;

    return 0;
}