#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,k;
    int answer = 0;
    vector <int> v;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        int coin;
        cin >> coin;
        v.push_back(coin);
    }

    for(int i=n-1;i>=0;i--) {
        while(v[i] <= k) {
            k-=v[i];
            answer++;
        }
    }

    cout << answer;

    return 0;
}