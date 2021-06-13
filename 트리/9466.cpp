#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;
int student[MAX];
bool visit[MAX];
bool is_cycle[MAX];
int t, n;
int cnt = 0;

void init()
{
    memset(visit, false, sizeof(visit));
    memset(is_cycle, false, sizeof(is_cycle));
}
void dfs(int num)
{
    visit[num] = true;
    int next = student[num];
    if (!visit[next])
    {
        dfs(next);
    }
    else if (!is_cycle[next])
    {
        for (int i = next; i != num; i = student[i])
            cnt++;
        cnt++;
    }
    is_cycle[num] = true;
}
void get_team()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            dfs(i);
        }
    }
}
int main()
{
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        init();
        cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> student[j];
        }
        get_team();
        cout << n - cnt << endl;
    }
    return 0;
}