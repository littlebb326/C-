#include <iostream>
#include <vector>
#include <map>
using namespace std;
int arr[26];
vector<string> sv;
map<char, int> m;
bool check[10];
int n, r;
int answer = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            m.insert(make_pair(s[j], 0));
        }
        sv.push_back(s);
    }
    r = m.size();
    permutation(0);
    cout << answer;
    // for (auto iter = m.begin(); iter != m.end(); iter++)
    // {
    //     cout << iter->first << " " << iter->second << endl;
    // }

    return 0;
}