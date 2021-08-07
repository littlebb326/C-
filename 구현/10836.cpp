#include <iostream>
#include <vector>
using namespace std;
int n, m;
int main()
{
    int num = 2 * m + 1;
    cin >> m >> n;
    vector<int> grow(2 * m - 1, 1);
    for (int i = 0; i < n; i++)
    {
        int idx = 0;
        int zero, one, two;
        cin >> zero >> one >> two;

        for (int j = zero; j < zero + one; j++)
        {
            grow[j]++;
        }

        for (int j = zero + one; j < 2 * m - 1; j++)
        {
            grow[j] += 2;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
                cout << grow[m - i - 1] << ' ';
            else
                cout << grow[m + j - 1] << ' ';
        }
        cout << endl;
    }

    return 0;
}