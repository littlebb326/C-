#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int,int> wire1, pair<int,int> wire2) {
    return wire1.first < wire2.first;
}
int main() {
    int n;
    int max = 0;
    int dp[100];
    vector<pair<int,int>> wire;

    cin >> n;
    for(int i=0;i<n;i++) {
        int first;
        int second;
        cin >> first >> second;
        wire.push_back(make_pair(first,second));
        dp[i] = 1;
    }
    sort(wire.begin(),wire.end(),compare);

    for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(wire[j].second < wire[i].second && dp[j] + 1 > dp[i])
                dp[i]++;
        }
        max = max > dp[i] ? max : dp[i];
    }

    cout << n - max;


    return 0;
}