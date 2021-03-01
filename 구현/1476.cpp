#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int e, s, m;
    cin >> e >> s >> m;
    int n = max(max(e,s),m);
    while(1) {
        if((n-e) % 15 ==0 && (n-s) % 28 == 0 && (n-m) % 19 == 0) {
            cout << n;
            break;
        }
        n++;        
    }
    return 0;
}