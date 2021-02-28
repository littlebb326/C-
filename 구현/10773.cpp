#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int k;
    long long sum = 0;
    vector<int> v;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        if (temp == 0)
            v.pop_back();
        else
            v.push_back(temp);
    }
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    cout << sum;

    return 0;
}