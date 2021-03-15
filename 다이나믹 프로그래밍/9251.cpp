#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 1001
int arr[1001][1001];
int main() {
    string a,b;

    cin >> a >> b;

    for(int i=1;i<=a.size();i++) {
        for(int j=1;j<=b.size();j++) {
            if(a[i-1] == b[j-1])
                arr[i][j] = arr[i-1][j-1] + 1;
            else {
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }

    cout << arr[a.size()][b.size()];

    return 0;
}