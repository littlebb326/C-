#include <iostream>
#include <string>
using namespace std;
int main()
{
    int alphabet_cnt = 0;
    int i = 0;
    string word;
    cin >> word;
    while (i < word.size())
    {
        if (word[i] == 'c')
        {
            if (i + 1 == word.size())
            {
                alphabet_cnt++;
            }
            else if (word[i + 1] == '=' || word[i + 1] == '-')
            {
                alphabet_cnt++;
                i += 2;
                continue;
            }
            else
                alphabet_cnt++;
        }
        else if (word[i] == 'd')
        {
            if (i + 1 == word.size())
                alphabet_cnt++;
            else if (i + 2 == word.size())
            {
                if (word[i + 1] == '-')
                {
                    alphabet_cnt++;
                    i += 2;
                    continue;
                }
                else
                {
                    alphabet_cnt++;
                }
            }
            else if (word.substr(i, 3) == "dz=")
            {
                alphabet_cnt++;
                i += 3;
                continue;
            }
            else if (word.substr(i, 2) == "d-")
            {
                alphabet_cnt++;
                i += 2;
                continue;
            }
            else
                alphabet_cnt++;
        }
        else if (word[i] == 'l')
        {
            if (i + 1 == word.size())
                alphabet_cnt++;
            else if (word[i + 1] == 'j')
            {
                alphabet_cnt++;
                i += 2;
                continue;
            }
            else
                alphabet_cnt++;
        }
        else if (word[i] == 'n')
        {
            if (i + 1 == word.size())
                alphabet_cnt++;
            else if (word[i + 1] == 'j')
            {
                alphabet_cnt++;
                i += 2;
                continue;
            }
            else
                alphabet_cnt++;
        }
        else if (word[i] == 's' || word[i] == 'z')
        {
            if (i + 1 == word.size())
                alphabet_cnt++;
            else if (word[i + 1] == '=')
            {
                alphabet_cnt++;
                i += 2;
                continue;
            }
            else
                alphabet_cnt++;
        }
        else
        {
            alphabet_cnt++;
        }
        i++;
    }
    cout << alphabet_cnt;
    return 0;
}