#include <iostream>
using namespace std;

int a, b;
bool is_find = false;
void dfs(int d, int k1, int k2)
{
    if (d == 2)
    {
        if (1 <= k1 && k1 <= k2)
        {
            is_find = true;
            a = k1;
            b = k2;
        }
        return;
        //todo
    }

    int next_k1 = k2 - k1;
    int next_k2 = k1;
    if (next_k1 < next_k2)
        dfs(d - 1, next_k1, next_k2);
}
int main()
{
    int d, k;
    cin >> d >> k;
    for (int i = 1; i <= (k / 2); i++)
    {
        dfs(d - 1, i, k - i);
        if (is_find)
            break;
    }
    cout << a << endl;
    cout << b;

    return 0;
}