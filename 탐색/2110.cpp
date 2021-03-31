#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> home;

int install(int distance) {
    int count = 1;
    int installed_pos = home[0];
    for(int i=1;i<home.size();i++) {
        if(home[i]-installed_pos >= distance) {
            count++;
            installed_pos = home[i];
        }
    }
    return count;
}
int search(int target_cnt) {
    int answer;
    int start = 1;
    int end = home[home.size()-1] - home[0];
    while(start<=end) {
        int mid = (start+end)/2;
        int count = install(mid);
        if(target_cnt > count)
            end = mid - 1;
        else{
            answer = mid;
            start = mid + 1;
        }
    }
    return answer;
}
int main() {
    int n, c, x;
    cin >> n >> c;
    for(int i=0;i<n;i++) {
        cin >> x;
        home.push_back(x);
    }
    sort(home.begin(),home.end());
    cout << search(c);

}