#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int main()
{
    priority_queue<int, vector<int>, greater<>> min_pq;
    priority_queue<int, vector<int>, less<>> max_pq;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);

        if (i % 2 == 0)
            max_pq.push(temp);
        else
            min_pq.push(temp);

        if (!min_pq.empty())
        {
            int max_top = max_pq.top();
            int min_top = min_pq.top();
            if (min_top < max_top)
            {
                max_pq.pop();
                max_pq.push(min_top);
                min_pq.pop();
                min_pq.push(max_top);
            }
        }
        printf("%d\n", max_pq.top());
    }

    return 0;
}