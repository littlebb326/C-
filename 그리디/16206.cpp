#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int ans = 0;
vector<int> v1;
vector<int> v2;
void cut_v1(int length)
{
    int cake_cnt = length / 10;
    int cut_cnt = (length / 10) - 1;

    if (m >= cut_cnt)
    {
        ans += cake_cnt;
        m -= cut_cnt;
    }
    else
    {
        ans += m;
        m = 0;
    }
}
void cut_v2(int length)
{
    int cake_cnt = length / 10;
    int cut_cnt = length / 10;

    if (m >= cut_cnt)
    {
        ans += cake_cnt;
        m -= cut_cnt;
    }
    else
    {
        ans += m;
        m = 0;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < 10)
            continue;
        else if (temp == 10)
        {
            ans++;
            continue;
        }
        else if (temp % 10 == 0)
        {
            v1.push_back(temp);
        }
        else
        {
            v2.push_back(temp);
        }
    }
    sort(v1.begin(), v1.end());

    for (int i = 0; i < v1.size(); i++)
    {
        if (m == 0)
            break;
        cut_v1(v1[i]);
    }

    for (int i = 0; i < v2.size(); i++)
    {
        if (m == 0)
            break;
        cut_v2(v2[i]);
    }

    cout << ans;

    return 0;
}