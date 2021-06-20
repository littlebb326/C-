#include <iostream>
#include <queue>
using namespace std;
struct Task
{
    int display, clipboard, time;
    Task(int _display, int _clipboard, int _time)
    {
        display = _display;
        clipboard = _clipboard;
        time = _time;
    }
};
bool visit[1001][1001];
int main()
{
    int s;
    int ans = 18181818;
    cin >> s;
    queue<Task> q;
    q.push(Task(1, 0, 0));
    visit[1][0] = true;
    while (!q.empty())
    {
        Task t = q.front();
        q.pop();

        if (t.display == s)
        {
            ans = ans > t.time ? t.time : ans;
            continue;
        }

        if (t.display > s)
            continue;

        if (!visit[t.display][t.display])
        {
            visit[t.display][t.display] = true;
            q.push(Task(t.display, t.display, t.time + 1));
        }

        if (t.clipboard > 0 && (t.display + t.clipboard) <= 1000 && !visit[t.display + t.clipboard][t.clipboard])
        {
            visit[t.display + t.clipboard][t.clipboard] = true;
            q.push(Task(t.display + t.clipboard, t.clipboard, t.time + 1));
        }

        if (t.display > 1 && !visit[t.display - 1][t.clipboard])
        {
            visit[t.display - 1][t.clipboard] = true;
            q.push(Task(t.display - 1, t.clipboard, t.time + 1));
        }
    }

    cout << ans;
    return 0;
}