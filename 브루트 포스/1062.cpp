#include <iostream>
#include <vector>
using namespace std;

int n, k, target_cnt;
int answer = 0;
vector<string> sv;
bool alphabet[26];

bool is_readable(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (!alphabet[s[i] - 'a'])
            return false;
    }
    return true;
}
int get_readable()
{
    int cnt = 0;
    for (int i = 0; i < sv.size(); i++)
    {
        if (is_readable(sv[i]))
        {
            cnt++;
        }
    }
    return cnt;
}
void get_letter(int idx, int cnt)
{
    if (cnt == target_cnt)
    {
        int readable = get_readable();
        answer = answer > readable ? answer : readable;
        return;
    }

    for (int i = idx; i < 26; i++)
    {
        if (alphabet[i] == true)
            continue;

        alphabet[i] = true;
        get_letter(i, cnt + 1);
        alphabet[i] = false;
    }
}
int main()
{
    cin >> n >> k;
    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['c' - 'a'] = true;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        sv.push_back(temp.substr(4, temp.size() - 8));
    }
    if (k < 5)
    {
        cout << 0;
        return 0;
    }
    else
    {
        target_cnt = k - 5;
        get_letter(0, 0);
        cout << answer;
    }
    return 0;
}