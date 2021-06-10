#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int n;
int ans = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    while (pq.size() >= 2)
    {
        int first, second, sum;
        first = pq.top();
        pq.pop();
        second = pq.top();
        pq.pop();
        sum = first + second;
        ans += sum;
        pq.push(sum);
    }
    cout << ans;
    return 0;
}