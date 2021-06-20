#include <iostream>
#include <vector>
using namespace std;

vector<int> tree_v[100001];
bool visit[100001];
int parent[100001];

void find_parent(int node)
{
    visit[node] = true;
    for (int i = 0; i < tree_v[node].size(); i++)
    {
        if (!visit[tree_v[node][i]])
        {
            parent[tree_v[node][i]] = node;
            find_parent(tree_v[node][i]);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        tree_v[a].push_back(b);
        tree_v[b].push_back(a);
    }
    find_parent(1);

    for (int i = 2; i <= n; i++)
        printf("%d\n", parent[i]);

    return 0;
}