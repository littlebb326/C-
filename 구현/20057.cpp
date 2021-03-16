#include <iostream>
#include <vector>
using namespace std;
#define MAX 499
int a[499][499];
int n;
int x,y;
int direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int sand_x[4][10] = {
    {0,0,-1,-1,-1,-1,-2,-2,-3,-2},
    {-1,1,-2,2,-1,1,-1,1,0,0},
    {0,0,1,1,1,1,2,2,3,2},
    {-1,1,-2,2,-1,1,-1,1,0,0},
};
int sand_y[4][10] = {
    {1,-1,2,-2,1,-1,1,-1,0,0},
    {0,0,1,1,1,1,2,2,3,2},
    {1,-1,2,-2,1,-1,1,-1,0,0},
    {0,0,-1,-1,-1,-1,-2,-2,-3,-2}
};
int sand_percent[9] = {1,1,2,2,7,7,10,10,5};
int direction_idx = 0;
int removed_sand = 0;
void print_map() {
    cout << "##### <map> #####" << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}
void move_sand(int x, int y) {
    // 현재 좌표 x, y 받아서 모래 이동
    int current_sand = a[y+direction[direction_idx][1]][x+direction[direction_idx][0]];
    int outside_sand = 0;
    int alpha_sand = a[y+direction[direction_idx][1]][x+direction[direction_idx][0]];
    int dir_x = direction[direction_idx][0];
    int dir_y = direction[direction_idx][1];

    for(int i=0;i<9;i++) { // alpha 제외
        int next_x = x+sand_x[direction_idx][i];
        int next_y = y+sand_y[direction_idx][i];
        int temp_sand = (current_sand * sand_percent[i])/100;
        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) { // 나간 경우
            outside_sand += temp_sand;
        } else {
            a[next_y][next_x] += temp_sand;
        }
        alpha_sand -= temp_sand;
    }
    int next_x = x+sand_x[direction_idx][9];
    int next_y = y+sand_y[direction_idx][9];
    if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) { // 나간 경우
            outside_sand += alpha_sand;
    } else {
        a[next_y][next_x] += alpha_sand;
    }
    a[y+direction[direction_idx][1]][x+direction[direction_idx][0]] = 0;
    removed_sand += outside_sand;
}
int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }
    x=y=n/2;
    for(int i=1;i<n;i++) {
        for(int j=0;j<2;j++) {
            for(int k=0;k<i;k++) {
                move_sand(x,y);
                int next_x = direction[direction_idx][0];
                int next_y = direction[direction_idx][1];
                x+=next_x;
                y+=next_y;
            }
            direction_idx = (direction_idx+1)%4;
        }
    }
    for(int i=0;i<n-1;i++) {
        move_sand(x,y);
        int next_x = direction[direction_idx][0];
        int next_y = direction[direction_idx][1];
        x+=next_x;
        y+=next_y;
    }
    cout << removed_sand << endl;

    return 0;
}