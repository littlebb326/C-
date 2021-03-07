#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    int cnt = 0;
    int max_val = -4000;
    int min_val = 4000;
    int arr[8001] = {
        0,
    };
    fill_n(arr, 8001, 0);
    vector<int> v;
    vector<int> v2;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sum += temp;
        v.push_back(temp);
        arr[temp + 4000]++;
        cnt = cnt > arr[temp + 4000] ? cnt : arr[temp + 4000];
        max_val = max_val > temp ? max_val : temp;
        min_val = min_val < temp ? min_val : temp;
    }
    sort(v.begin(), v.end());
    cout << round(sum / (double)n) << endl;
    cout << v[(n - 1) / 2] << endl;
    for (int i = 0; i <= 8000; i++)
    {
        if (cnt == arr[i])
            v2.push_back(i);
    }
    if (v2.size() == 1)
        cout << v2[0] - 4000 << endl;
    else
    {
        sort(v2.begin(), v2.end());
        cout << v2[1] - 4000 << endl;
    }
    cout << max_val - min_val;

    return 0;
}