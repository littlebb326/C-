#include <iostream>
#include <queue>
using namespace std;

struct Edge
{
    int r, c, cost;
    bool is_break;

    Edge(int _r, int _c, int _cost, bool _is_break) {
        r = _r;
        c = _c;
        cost = _cost;
        is_break = _is_break;
    }
};

int map[1001][1001];
int dir[4][2] = {{1,0},{-1,0}, {0,-1},{0,1}};
bool visit[1001][1001][2];
int n, m;
void print_edge(Edge e) {
    cout << "<" << e.r << ' ' << e.c << "> " << e.is_break << ' ' << e.cost << endl;
}
int main() {
    queue<Edge> q;
    cin >> n >> m;
    int temp_r, temp_c, temp_cost;
    bool temp_is_break;
    bool is_possible = false;

    for(int i=1;i<=n;i++) {
        string temp;
        cin >> temp;
        for(int j=1;j<=m;j++) {
            map[i][j] = temp[j-1] - '0';
        }
    }

    q.push(Edge(1,1,1,false));
    visit[1][1][0] = true;
    visit[1][1][1] = true;
    while(!q.empty()) {
        temp_r = q.front().r;
        temp_c = q.front().c;
        temp_cost = q.front().cost;
        temp_is_break = q.front().is_break;
        q.pop();
        if(temp_r == n && temp_c == m) {
            is_possible = true;
            break;
        }
        for(int i=0;i<4;i++) {
            int next_r = temp_r + dir[i][0];
            int next_c = temp_c + dir[i][1];
            if(next_r > 0 && next_c > 0 && next_r <= n && next_c <= m) {
                if(!visit[next_r][next_c][0]) {
                    if(map[next_r][next_c] == 0 && !temp_is_break) {
                        q.push(Edge(next_r,next_c, temp_cost + 1, temp_is_break));
                        visit[next_r][next_c][0] = true;
                    }
                }
                if(!visit[next_r][next_c][1]) {
                    if((map[next_r][next_c] == 1 && !temp_is_break) || (map[next_r][next_c] == 0 && temp_is_break)) {
                        q.push(Edge(next_r,next_c, temp_cost + 1, true));
                        visit[next_r][next_c][1] = true;
                    }
                }
            }
        }
    }

    if(is_possible) {
        cout << temp_cost;
    } else {
        cout << -1;
    }

    return 0;
}