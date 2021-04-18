#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> bridge_arr[10001];
bool visit[10001];
int n, m;
int f1, f2;
int answer;
bool is_possible = false;
void init_visit()
{
    for (int i = 1; i <= 10000; i++)
        visit[i] = false;
}
bool bfs(int start, int weight)
{
    init_visit();
    queue<int> q;
    q.push(start);
    visit[start] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        if (temp == f2)
            return true;

        for (int i = 0; i < bridge_arr[temp].size(); i++)
        {
            if (!visit[bridge_arr[temp][i].first] && bridge_arr[temp][i].second >= weight)
            {
                q.push(bridge_arr[temp][i].first);
                visit[bridge_arr[temp][i].first] = true;
            }
        }
    }
    return false;
}
void binary_search()
{
    init_visit();
    int left, right, mid;
    left = 1;
    right = 1000000000;
    while (left <= right)
    {
        mid = (left + right) / 2;
        is_possible = bfs(f1, mid);
        if (is_possible)
        {
            left = mid + 1;
            answer = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bridge_arr[a].push_back(make_pair(b, c));
        bridge_arr[b].push_back(make_pair(a, c));
    }
    cin >> f1 >> f2;

    binary_search();
    cout << answer;

    return 0;
}