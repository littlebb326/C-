#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int r1, c1, r2, c2;

int getValueByPos(int r, int c)
{
    int max_abs = max(abs(r), abs(c));
    int bottom_right = (2 * max_abs + 1);
    bottom_right *= bottom_right;
    int diff = 2 * max_abs;

    if (r == max_abs)
        return bottom_right - (max_abs - c);
    bottom_right -= diff;
    if (c == (0 - max_abs))
        return bottom_right - (max_abs - r);
    bottom_right -= diff;
    if (r == (0 - max_abs))
        return bottom_right - (max_abs + c);
    bottom_right -= diff;
    return bottom_right - (max_abs + r);
}

int get_digit(int num)
{
    string str = to_string(num);
    return str.length();
}

int main()
{
    cin >> r1 >> c1 >> r2 >> c2;
    int max_digit = 0;
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            max_digit = max(max_digit, get_digit(getValueByPos(i, j)));
        }
    }
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            printf("%*d ", max_digit, getValueByPos(i, j));
        }
        printf("\n");
    }
    return 0;
}