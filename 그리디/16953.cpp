#include <iostream>
#include <string>
using namespace std;
int a, b;
int main()
{
    int count = 0;
    cin >> a >> b;
    while (a < b)
    {
        string s = to_string(b);
        int last_idx = s.length() - 1;
        if (s[last_idx] == '1')
        {
            b = stoi(s.erase(last_idx, 1));
        }
        else
        {
            if (b % 2 != 0)
            {
                cout << -1;
                return 0;
            }
            else
            {
                b /= 2;
            }
        }
        count++;
    }
    if (a == b)
    {
        cout << count + 1;
    }
    else
    {
        cout << -1;
    }
    return 0;
}