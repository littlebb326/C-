#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct compare
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.first == p2.first)
        {
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
priority_queue<int, vector<int>, greater<int>> tq;
int n, s, t;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        pq.push(make_pair(s, t));
    }

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        if (tq.empty())
        {
            tq.push(p.second);
        }
        else
        {
            if (p.first >= tq.top())
            {
                tq.pop();
                tq.push(p.second);
            }
            else
            {
                tq.push(p.second);
            }
        }
    }

    cout << tq.size();

    return 0;
}