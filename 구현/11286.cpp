#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct compare{
    bool operator()(int n1, int n2) {
        if(abs(n1) == abs(n2))
            return n1 > n2;
        else
            return abs(n1) > abs(n2);
    }
};
int main() {
    int n;
    priority_queue<int,vector<int>,compare> pq;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    for(int i=0;i<n;i++) {
        if(v[i] == 0) {
            if(pq.empty())
                cout << 0 << endl;
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        } else {
            pq.push(v[i]);
        }
    }
    return 0;
}