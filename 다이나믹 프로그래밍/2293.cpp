#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n,k;
    int arr[10001] = {0};
    vector<int> coins;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }
    sort(coins.begin(),coins.end());
    arr[0] = 1;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            if(j-coins[i-1] >= 0)
                arr[j] += arr[j-coins[i-1]];
        }
    }

    cout << arr[k];

    return 0;
}