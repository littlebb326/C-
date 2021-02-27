#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define GROUP_WORD 1;
#define NOT_GROUP_WORD 0;

int find_group_word(string word);
string compress_word(string word);
int main()
{
    int n;
    int result = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        result += find_group_word(word);
    }

    cout << result;
    return 0;
}

int find_group_word(string word)
{
    string compressed_word = compress_word(word);
    sort(compressed_word.begin(), compressed_word.end());
    //cout << compressed_word;

    for (int i = 1; i < compressed_word.size(); i++)
    {
        if (compressed_word[i - 1] == compressed_word[i])
            return NOT_GROUP_WORD;
    }

    return GROUP_WORD;
}
string compress_word(string word)
{
    string compressed_word = "";
    int i = 0;
    while (i < word.size())
    {
        int char_cnt = 1;
        compressed_word.push_back(word[i]);
        for (int j = i + 1; j < word.size(); j++)
        {
            if (word[i] == word[j])
            {
                char_cnt++;
            }
            else
            {
                break;
            }
        }
        i += char_cnt;
    }
    return compressed_word;
}