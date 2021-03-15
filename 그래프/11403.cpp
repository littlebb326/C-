#include <iostream>
#include <vector>
using namespace std;
#define MAX 101
int n;
vector<int> route;
vector<int> arr[MAX];
int answer[MAX][MAX];
bool check[MAX];
void DFS(int a) {
    if(route.size() > 0)
        check[a] = true;
    route.push_back(a);
    for(int i=0;i<arr[a].size();i++) {
        if(!check[arr[a][i]])
            DFS(arr[a][i]);
    }
}
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int temp;
            cin >> temp;
            if(temp == 1)
                arr[i].push_back(j);
        }
    }

    for(int i=1;i<=n;i++) {
        route.clear();
        fill_n(check,MAX+1,false);
        DFS(i);
        for(int j=1;j<route.size();j++) {
            answer[i][route[j]] = 1;
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout << answer[i][j] << ' ';
        }
        cout <<endl;
    }

    return 0;
}