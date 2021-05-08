#include <iostream>
#include <vector>
using namespace std;

struct Student
{
    int number = 0;
    vector<int> favorite;
};
Student classRoom[21][21];
vector<pair<int, int>> pos_v;
vector<pair<int, int>> empty_pos_v;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int happy[5] = {0, 1, 10, 100, 1000};
int n;
pair<int, int> get_pos(Student s)
{
    int max_cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int favorite_cnt = 0;
            if (classRoom[i][j].number != 0)
                continue;
            for (int k = 0; k < 4; k++)
            {
                int next_r = i + dir[k][0];
                int next_c = j + dir[k][1];
                if (next_r > 0 && next_c > 0 && next_r <= n && next_c <= n)
                {
                    if (classRoom[next_r][next_c].number != 0) // isNotEmpty
                    {
                        for (int l = 0; l < 4; l++)
                        {
                            if (classRoom[next_r][next_c].number == s.favorite[l])
                                favorite_cnt++;
                        }
                    }
                }
            }
            if (max_cnt < favorite_cnt)
            {
                pos_v.clear();
                pos_v.push_back(make_pair(i, j));
                max_cnt = favorite_cnt;
            }
            else if (max_cnt == favorite_cnt)
            {
                pos_v.push_back(make_pair(i, j));
            }
        }
    }
    if (pos_v.size() > 1)
    {
        int max_empty_cnt = 0;
        for (int i = 0; i < pos_v.size(); i++)
        {
            //  cout << "get empty pos : " << pos_v[i].first << ' ' << pos_v[i].second << endl;
            int empty_cnt = 0;
            for (int j = 0; j < 4; j++)
            {
                int next_r = pos_v[i].first + dir[j][0];
                int next_c = pos_v[i].second + dir[j][1];
                if (next_r > 0 && next_c > 0 && next_r <= n && next_c <= n)
                {
                    if (classRoom[next_r][next_c].number == 0) // isEmpty
                        empty_cnt++;
                }
            }
            if (max_empty_cnt < empty_cnt)
            {
                empty_pos_v.clear();
                empty_pos_v.push_back(pos_v[i]);
                max_empty_cnt = empty_cnt;
            }
            else if (max_empty_cnt == empty_cnt)
            {
                empty_pos_v.push_back(pos_v[i]);
            }
        }
    }
    else
    {
        return pos_v[0];
    }
    return empty_pos_v[0];
}

int get_happy()
{
    int happiness = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int favorite_cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                int next_r = i + dir[k][0];
                int next_c = j + dir[k][1];
                if (next_r > 0 && next_c > 0 && next_r <= n && next_c <= n)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        if (classRoom[next_r][next_c].number == classRoom[i][j].favorite[l])
                            favorite_cnt++;
                    }
                }
            }
            //cout << "favorite : " << favorite_cnt << endl;
            happiness += happy[favorite_cnt];
        }
    }
    return happiness;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n * n; i++)
    {
        Student s;
        cin >> s.number;
        for (int j = 0; j < 4; j++)
        {
            int temp;
            cin >> temp;
            s.favorite.push_back(temp);
        }
        pos_v.clear();
        empty_pos_v.clear();
        //cout << "start get position" << endl;
        pair<int, int> pos = get_pos(s);
        //cout << "pos : " << pos.first << ' ' << pos.second << endl;
        classRoom[pos.first][pos.second] = s;
    }
    int answer = get_happy();
    cout << answer;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         Student s = classRoom[i][j];
    //         //cout << '(' << i << ", " << j << ") : " << s.number << endl;
    //     }
    // }

    return 0;
}