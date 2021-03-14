#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> arr[1001];
bool check[1001];
void DFS(int n)
{
    cout << n << ' ';
    for (int i = 0; i < arr[n].size(); i++)
    {
        if (!check[arr[n][i]])
        {
            check[arr[n][i]] = true;
            DFS(arr[n][i]);
        }
    }
}
void BFS(int n)
{
    queue<int> q;
    q.push(n);
    check[n] = true;
    while (!q.empty())
    {
        cout << q.front() << ' ';
        for (int i = 0; i < arr[q.front()].size(); i++)
        {
            if (!check[arr[q.front()][i]])
            {
                q.push(arr[q.front()][i]);
                check[arr[q.front()][i]] = true;
            }
        }
        q.pop();
    }
}
int main()
{
    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        arr[start].push_back(end);
        arr[end].push_back(start);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }
    check[v] = true;
    DFS(v);
    fill_n(check, 1001, false);
    cout << endl;
    BFS(v);

    return 0;
}