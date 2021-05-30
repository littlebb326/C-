#include <iostream>
#include <vector>
using namespace std;
int n, k;
int max_score;
vector<int> paper;
bool is_possible(int target)
{
    int sum = 0;
    int group_cnt = 0;
    for (int i = 0; i < paper.size(); i++)
    {
        sum += paper[i];
        if (sum >= target)
        {
            sum = 0;
            group_cnt++;
            if (group_cnt == k)
                return true;
        }
    }
    return false;
}
int main()
{
    int answer;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        paper.push_back(temp);
    }
    max_score = (n / k) * 20;

    int l = 0;
    int r = max_score;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (is_possible(m))
        {
            l = m + 1;
            answer = m;
        }
        else
        {
            r = m - 1;
        }
    }
    cout << answer;
    return 0;
}