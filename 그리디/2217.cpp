#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int max_val = 0;
    vector <int> v;
    cin >> n;

    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++) {
        max_val=max(max_val,v[i] * (i+1));
    }
    cout << max_val;
    return 0;
}