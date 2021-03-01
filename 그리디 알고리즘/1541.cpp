#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string text;
    int start_idx = 0;
    int end_idx = 0;
    int answer = 0;
    bool is_first_minus = false;
    vector <string> v;
    cin >> text;
   
    while(end_idx < text.size()) {
        if(text[end_idx] == '-' || text[end_idx] == '+') {
            //cout << text.substr(start_idx,end_idx-start_idx) << endl;
            string s = "";
            v.push_back(text.substr(start_idx,end_idx-start_idx));
            s.push_back(text[end_idx]);
            v.push_back(s);
            start_idx = end_idx+1;
        }
        end_idx++;
    }
    v.push_back(text.substr(start_idx,end_idx-start_idx));
    for(int i=0;i<v.size();i++) {
        if(!is_first_minus && v[i] == "-")
            is_first_minus = true;
        if(v[i] != "-" && v[i] != "+")
        {
            if(is_first_minus)
                answer -= stoi(v[i]);
            else
                answer += stoi(v[i]);               
        }
    }
    cout << answer;
    return 0;
}