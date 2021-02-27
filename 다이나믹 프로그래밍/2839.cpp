#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int result = 0;
    int n = 0;
    cin >> n;
    int *sugar = new int[n + 1];
    fill_n(sugar, n + 1, 9999);
    sugar[3] = 1;
    sugar[5] = 1;

    for (int i = 6; i <= n; i++)
    {
        sugar[i] = min(sugar[i - 3], sugar[i - 5]) + 1;
    }

    if (sugar[n] == 9999 || sugar[n] == 10000)
        result = -1;
    else
        result = sugar[n];
    cout << result;
    delete[] sugar;
    return 0;
}