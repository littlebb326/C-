#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string func, input_arr;
        int n;
        int arr[100001];

        bool is_reversed = false;
        bool is_error = false;
        int f_idx, e_idx, s_idx, arr_size;
        cin >> func >> n >> input_arr;
        if (n > 0)
        {
            int str_idx = 1;
            int str_e_idx = 0;
            int com_idx;
            for (int j = 0; j < n - 1; j++)
            {
                com_idx = input_arr.find(",", str_idx);
                arr[j] = stoi(input_arr.substr(str_idx, com_idx - str_idx));
                str_idx = com_idx + 1;
            }
            com_idx = input_arr.find("]", str_idx);
            arr[n - 1] = stoi(input_arr.substr(str_idx, com_idx - str_idx));
        }

        f_idx = 0;
        arr_size = n;
        e_idx = arr_size - 1;
        s_idx = 0;

        for (int j = 0; j < arr_size; j++)
        {
            //cout << arr[j] << ' ';
        }
        //cout << endl;

        //cout << "f : " << f_idx << ", e : " << e_idx << ", size : " << arr_size << endl;
        for (int j = s_idx; j < func.size(); j++)
        {
            //cout << func[j] << ' ';
        }
        //cout << endl;
        while (s_idx < func.size())
        {
            if (arr_size == 0)
            {
                is_error = true;
                break;
            }
            if (func[s_idx] == 'R')
            {
                is_reversed = !is_reversed;
                //cout << "reversed : " << is_reversed << endl;
            }
            else
            {
                arr_size--;
                if (is_reversed)
                {
                    e_idx--;
                    //cout << "e_idx : " << e_idx << endl;
                }
                else
                {
                    f_idx++;
                    //cout << "f_idx : " << f_idx << endl;
                }
            }
            s_idx++;
        }
        if (is_error)
            cout << "error" << endl;
        else
        {
            cout << '[';
            if (arr_size > 0)
            {
                if (is_reversed)
                {
                    cout << arr[e_idx];
                    e_idx--;
                    for (int j = e_idx; j >= f_idx; j--)
                    {
                        cout << ',' << arr[j];
                    }
                }
                else
                {
                    cout << arr[f_idx];
                    f_idx++;
                    for (int j = f_idx; j <= e_idx; j++)
                    {
                        cout << ',' << arr[j];
                    }
                }
            }
            cout << ']' << endl;
        }
    }
    return 0;
}