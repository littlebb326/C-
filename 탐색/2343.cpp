#include <iostream>
using namespace std;
int n, m;
int lesson[100001];
bool binary_search(int target)
{
    int count = 1;
    int length_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (lesson[i] > target)
            return false;

        length_sum += lesson[i];
        if (length_sum > target)
        {
            count++;
            length_sum = lesson[i];
        }
    }

    return (count <= m);
}
int main()
{
    int left = 1;
    int right = 0;
    int mid = 0;
    int ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> lesson[i];
        right += lesson[i];
    }

    while (left <= right)
    {
        mid = (left + right) / 2;
        bool is_possible = binary_search(mid);
        if (is_possible)
        {
            right = mid - 1;
            ans = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}