#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int k, v, e;
vector<int> graph[20001];
int color_arr[20001];
bool visit[20001];

void init()
{
    for (int i = 1; i <= 20000; i++)
    {
        graph[i].clear();
        visit[i] = false;
        color_arr[i] = 0;
    }
}
bool bfs(int start)
{
    color_arr[start] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(start, 1));
    visit[start] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int front = p.first;
        int depth = p.second;
        q.pop();
        int next_color = depth % 2 == 1 ? 2 : 1;

        for (int i = 0; i < graph[front].size(); i++)
        {
            int next = graph[front][i];
            if (visit[next] && color_arr[next] != next_color)
            {
                return false;
            }
            else if (!visit[next])
            {
                color_arr[next] = next_color;
                visit[next] = true;
                q.push(make_pair(next, depth + 1));
            }
        }
    }
    return true;
}
int main()
{
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        init();
        bool isSuccess = true;
        cin >> v >> e;
        for (int j = 0; j < e; j++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (int j = 1; j <= v; j++)
        {
            if (!visit[j])
            {
                isSuccess = bfs(j);
                if (!isSuccess)
                {
                    cout << "NO" << endl;
                    break;
                }
            }
        }
        if (isSuccess)
            cout << "YES" << endl;
    }
    return 0;
}