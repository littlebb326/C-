#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int first, second;
        cin >> first >> second;
        v.push_back(make_pair(first, second));
    }
    for (int i = 0; i < n; i++)
    {
        int k = 1;
        for (int j = 0; j < n; j++)
        {
            if (v[i].first < v[j].first && v[i].second < v[j].second)
                k++;
        }
        cout << k << ' ';
    }
    return 0;
}
