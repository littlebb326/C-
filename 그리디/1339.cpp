#include <iostream>
#include <algorithm>
using namespace std;
int alphabet[26];
int n;
bool compare(int a, int b)
{
    return a > b;
}
int main()
{
    cin >> n;
    int answer = 0;
    int num = 9;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int size = s.size();
        int digit = 1;
        for (int j = size - 1; j >= 0; j--)
        {
            alphabet[(int)s[j] - 65] += digit;
            digit *= 10;
        }
    }

    sort(alphabet, alphabet + 26, compare);
    for (int i = 0; i < 10; i++)
    {
        answer += alphabet[i] * num;
        num--;
    }
    cout << answer;

    return 0;
}