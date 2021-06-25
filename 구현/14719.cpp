#include <iostream>
using namespace std;
int h, w;
int max_h = 0;
int max_idx = 0;
int left_max_h = 0;
int right_max_h = 0;
int water = 0;
int map[501];
int main()
{
    cin >> h >> w;
    for (int i = 1; i <= w; i++)
    {
        cin >> map[i];
        if (max_h < map[i])
        {
            max_h = map[i];
            max_idx = i;
        }
    }
    // left
    left_max_h = map[1];
    for (int i = 2; i <= max_idx; i++)
    {
        if (map[i] < left_max_h)
        {
            water += (left_max_h - map[i]);
        }
        else
        {
            left_max_h = map[i];
        }
    }
    //right
    right_max_h = map[w];
    for (int i = w; i >= max_idx; i--)
    {
        if (map[i] < right_max_h)
        {
            water += (right_max_h - map[i]);
        }
        else
        {
            right_max_h = map[i];
        }
    }

    cout << water;
}