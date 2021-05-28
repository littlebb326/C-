#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t, n, oper_cnt;
char arr[3] = {' ', '+', '-'};

void get_result(string s)
{
    int s_idx = 0;
    int e_idx = 0;
    int result = 0;
    string temp = s;
    string s2 = "";
    vector<int> num;
    vector<char> oper;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        else
            s2 += s[i];
    }
    while (e_idx != s2.size())
    {
        if (s2[e_idx] == '+' || s2[e_idx] == '-')
        {
            num.push_back(stoi(s2.substr(s_idx, e_idx - s_idx)));
            oper.push_back(s2[e_idx]);
            s_idx = e_idx + 1;
        }
        e_idx++;
    }
    num.push_back(stoi(s2.substr(s_idx, e_idx - s_idx)));

    result = num[0];
    for (int i = 0; i < oper.size(); i++)
    {
        if (oper[i] == '+')
            result += num[i + 1];
        else
            result -= num[i + 1];
    }
    if (result == 0)
    {
        cout << temp << endl;
    }
}
void solve(vector<char> v)
{
    if (v.size() == oper_cnt)
    {
        string s = "";
        for (int i = 1; i < n; i++)
        {
            s += to_string(i);
            s += v[i - 1];
        }
        s += to_string(n);
        get_result(s);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        v.push_back(arr[i]);
        solve(v);
        v.pop_back();
    }
}
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vector<char> v;
        cin >> n;
        oper_cnt = n - 1;
        for (int j = 0; j < 3; j++)
        {
            v.push_back(arr[j]);
            solve(v);
            v.pop_back();
        }
        cout << endl;
    }
    return 0;
}