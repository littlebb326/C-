#include <iostream>
#include <string>
using namespace std;

int t;

bool check(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}
int main()
{
    cin >> t;
    string s;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        int start = 0;
        int end = s.length() - 1;
        bool isRemoved = false;
        while (start < end)
        {
            if (s[start] != s[end])
            {
                string origin = s;
                string temp1 = s.erase(start, 1);
                string temp2 = origin.erase(end, 1);
                isRemoved = true;

                if (check(temp1))
                {
                    cout << 1 << endl;
                }
                else if (check(temp2))
                {
                    cout << 1 << endl;
                }
                else
                {
                    cout << 2 << endl;
                }
                break;
            }
            else
            {
                start++;
                end--;
            }
        }

        if (!isRemoved)
        {
            cout << 0 << endl;
        }
    }
    return 0;
}