#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector <int> v;
    int n;
    int answer = 0;
    cin >> n;
    for(int i=0;i<n;i++) {
        int time;
        cin >> time;
        v.push_back(time);
    }
    sort(v.begin(),v.end());

    for(int i=0;i<n;i++) {
        answer += v[i]*(n-i);
    }
    cout << answer;
    
    return 0;
}