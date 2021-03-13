#include <iostream>
#include <vector>
using namespace std;
bool check[1001];
vector<int> arr[1001];
int count = 0;
void DFS(int n)
{
    check[n] = true;
    for (int i = 0; i < arr[n].size(); i++)
    {
        if (!check[arr[n][i]])
        {
            DFS(arr[n][i]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        arr[start].push_back(end);
        arr[end].push_back(start);
    }

    for (int i = 1; i <= n; i++)
    {
        if (check[i])
            continue;
        else
        {
            DFS(i);
            count++;
        }
    }

    cout << count;

    return 0;
}