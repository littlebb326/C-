#include <iostream>
#include <algorithm>
using namespace std;
int t, n, g1, g2;
pair<int, int> employee[100000];
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> g1 >> g2;
            employee[j] = make_pair(g1, g2);
        }
        sort(employee, employee + n);

        int ans = 1;
        int iRank = employee[0].second;

        for (int j = 1; j < n; j++)
        {
            if (employee[j].second < iRank)
            {
                ans++;
                iRank = employee[j].second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}