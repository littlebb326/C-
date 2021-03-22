#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, route_count;
int map[25][25];
bool check[25][25];
vector <int> v;
int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
void dfs(int x, int y) {
    check[x][y] = true;
    route_count++;
    for(int i=0;i<4;i++) {
        int next_x = x+dir[i][0];
        int next_y = y+dir[i][1];
        if(check[next_x][next_y] || map[next_x][next_y] == 0 || next_x < 0 || next_y < 0 || next_x >= n || next_y >= n)
            continue;
        else
            dfs(next_x, next_y);
    }
}
int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(map[i][j] == 1 && !check[i][j]) {
                route_count = 0;
                dfs(i,j);
                v.push_back(route_count);    
            }
        }
    }

    cout << v.size() << endl;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout << v[i] << endl;


    return 0;
}