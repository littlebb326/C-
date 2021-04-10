#include <iostream>
#include <vector>
#define MAX_R 12
#define MAX_C 6
using namespace std;

char board[MAX_R][MAX_C];
bool visit[MAX_R][MAX_C];
int chain_cnt = 0;
vector<pair<int,int>> removed_puyo;
bool is_removed = false;

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void print() {
    cout << endl;
    cout << "###################" << endl;
    for(int i=0;i<MAX_R;i++) {
        for(int j=0;j<MAX_C;j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}
void init_visit() {
    for(int i=0;i<MAX_R;i++) {
        for(int j=0;j<MAX_C;j++) {
            visit[i][j] = false;
        }
    }
}
void dfs(int r, int c, char target) {
    visit[r][c] = true;
    removed_puyo.push_back(make_pair(r,c));
    for(int i=0;i<4;i++) {
        int next_r = r + dir[i][0];
        int next_c = c + dir[i][1];
        if (next_r >=0 && next_r < MAX_R && next_c >=0 && next_c < MAX_C) {
            if(!visit[next_r][next_c] && board[next_r][next_c] == target)
                dfs(next_r,next_c, target);
        }
    }
}
void remove_puyo() {
    init_visit();
    for(int i=0;i<MAX_R;i++) {
        for(int j=0;j<MAX_C;j++) {
            if(!visit[i][j] && board[i][j] != '.') {
                removed_puyo.clear();
                dfs(i,j,board[i][j]);
                if(removed_puyo.size() >= 4) {
                    is_removed = true;
                    for(int k=0;k<removed_puyo.size();k++)
                        board[removed_puyo[k].first][removed_puyo[k].second] = '.';
                }                    
            }
        }
    }
}
void drop_puyo() {
    for(int j=0;j<MAX_C;j++) {
        vector<char> temp;
        for(int i=MAX_R-1;i>=0;i--) {
            if(board[i][j] != '.') {
                temp.push_back(board[i][j]);
                board[i][j] = '.';
            }
        }
        for(int i=0;i<temp.size();i++) {
            board[MAX_R-1-i][j] = temp[i];
        }
    }
}
int main() {
    for(int i=0;i<MAX_R;i++) {
        for(int j=0;j<MAX_C;j++) {
            cin >> board[i][j];
        }
    }

    do
    {
        is_removed = false;
        remove_puyo();
        drop_puyo();
        if(is_removed)
            chain_cnt++;
    } while (is_removed);
    
    cout << chain_cnt;

    return 0;
}