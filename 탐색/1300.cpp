#include <iostream>
using namespace std;
int n,k;
int get_cnt(int start, int end) {
    int count = 0;
    int mid = (end+start)/2;
    for(int i=1;i<=n;i++) {
        if(mid/i > n)
            count+=n;
        else
            count+=mid/i;
    }
    return count;
}
int main() {
    cin >> n >> k;
    int start = 1;
    int end = k;
    int answer;

    while(start <= end) {
        int mid = (end+start)/2;
        int count = get_cnt(start, end);
        if(count >= k) {
            answer = mid;
            end = mid-1;
        } else {
            start = mid+1;
        }
    }

    cout << answer;

    return 0;
}