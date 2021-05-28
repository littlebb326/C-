#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Road
{
    int start, end, cost;
    Road(int _start, int _end, int _cost)
    {
        start = _start;
        end = _end;
        cost = _cost;
    }
};
bool compare(Road r1, Road r2)
{
    return r1.cost < r2.cost;
}
int n, m;
int total_cost = 0;
int root[100001];
vector<Road> rv;

int find(int x)
{
    if (root[x] == x)
    {
        return x;
    }
    else
    {
        return root[x] = find(root[x]);
    }
}
void get_union(int x, int y)
{
    int x2 = find(x);
    int y2 = find(y);

    if (x2 == y2)
        return;

    root[y2] = x2;
}
int main()
{
    int idx = 0;
    int count = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        rv.push_back(Road(a, b, c));
    }
    sort(rv.begin(), rv.end(), compare);

    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
    }

    while (count < n - 2)
    {
        Road r = rv[idx];
        if (find(r.start) != find(r.end))
        {
            total_cost += r.cost;
            count++;
            get_union(r.start, r.end);
        }
        idx++;
    }

    cout << total_cost;

    return 0;
}