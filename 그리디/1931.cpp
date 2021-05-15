#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}
int main() {
    int n;
    int end = 0;
    int count = 0;
    vector<pair <int,int>> v;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        int first, second;
        cin >> first >> second;
        v.push_back(make_pair(first, second));
    }

    sort(v.begin(),v.end(),compare);

    for(int i=0;i<n;i++) {
        if(v[i].first >= end) {
            end = v[i].second;
            count++;
        }
    }
    cout << count;

    return 0;
}