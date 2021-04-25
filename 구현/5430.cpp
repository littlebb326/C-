#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main()
{
    int t, n;
    string func, arr;
    deque<int> dq;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        bool is_reversed = false;
        bool is_error = false;
        cin >> func >> n >> arr;
        if (n > 0)
        {
            int f_idx = 1;
            int e_idx = 0;
            for (int j = 0; j < n - 1; j++)
            {
                e_idx = arr.find(",", f_idx);
                dq.push_back(stoi(arr.substr(f_idx, e_idx - f_idx)));
                f_idx = e_idx + 1;
            }
            e_idx = arr.find("]", f_idx);
            dq.push_back(stoi(arr.substr(f_idx, e_idx - f_idx)));
        }

        for (int j = 0; j < func.size(); j++)
        {
            if (func[j] == 'R')
                is_reversed = !is_reversed;
            else
            {
                if (dq.size() <= 0)
                {
                    is_error = true;
                    break;
                }
                if (is_reversed)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }

        if (is_error)
            cout << "error" << endl;
        else
        {
            cout << '[';
            if (is_reversed)
            {
                int size = dq.size();
                if (size > 0)
                    cout << dq[size - 1];
                for (int j = size - 2; j >= 0; j--)
                {
                    cout << ',' << dq[j];
                }
            }
            else
            {
                int size = dq.size();
                if (size > 0)
                    cout << dq[0];
                for (int j = 1; j < size; j++)
                {
                    cout << ',' << dq[j];
                }
            }

            cout << ']' << endl;
        }

        dq.clear();
    }
    return 0;
}