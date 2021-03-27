#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Fireball {
    int r;
    int c;
    int m;
    int s;
    int d;
};
int n, m, k;
vector<Fireball> map[51][51];
int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int same_dir[4] = {0, 2, 4, 6};
int diff_dir[4] = {1, 3, 5, 7};
vector<Fireball> v;
int get_position(int p) {
    if(p > n) {
        int temp = p % n;
        if(temp == 0)
            return n;
        else
            return temp;
    }
    else if(p <= 0) {
        int temp = abs(p) / n;
        return p + ((temp + 1) * n);
    }
    else {
        return p;
    }
}
void move_fireball() {

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            map[i][j].clear();
        }
    }

    for(int i=0;i<v.size();i++) {
        v[i].r = get_position(v[i].r + (dir[v[i].d][0] * v[i].s));
        v[i].c = get_position(v[i].c + (dir[v[i].d][1] * v[i].s));
        map[v[i].r][v[i].c].push_back(v[i]);
    }
}
void divide_fireball() {
    vector<Fireball> temp;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(map[i][j].size() >= 2) {
                int m = 0;
                int s = 0;
                int odd = 0;
                int even = 0;
                for(int k=0;k<map[i][j].size();k++) {
                    if(map[i][j][k].d % 2 == 0)
                        even++;
                    else
                        odd++;
                    m += map[i][j][k].m;
                    s += map[i][j][k].s;
                }
                if(m / 5 > 0) { // 질량이 존재
                    m /= 5;
                    s /= map[i][j].size();
                    Fireball fb = {i,j,m,s};
                    if(odd == 0 || even == 0) {
                        for(int l=0;l<4;l++) {
                            fb.d = same_dir[l];
                            temp.push_back(fb);
                        }                        
                    } else {
                        for(int l=0;l<4;l++) {
                            fb.d = diff_dir[l];
                            temp.push_back(fb);
                        }
                    }
                }
            } else if(map[i][j].size() == 1){
                temp.push_back(map[i][j][0]);
            }
        }
    }
    v.clear();
    v = temp;
}
int get_total_m() {
    int total_m = 0;
    for(int i=0;i<v.size();i++) {
        total_m += v[i].m;
    }
    return total_m;
}
void print() {
    cout << "### count map ###" << endl;
    for(int i=0;i<v.size();i++)
        cout << v[i].r << ' ' << v[i].c << ' ' << v[i].m << ' ' << v[i].s << ' ' << v[i].d << endl;
}
int main() {

    cin >> n >> m >> k;
    for(int i=0;i<m;i++) {
        Fireball fb;
        cin >> fb.r >> fb.c >> fb.m >> fb.s >> fb.d;
        map[fb.r][fb.c].push_back(fb);
        v.push_back(fb);
    }
    for(int i=0;i<k;i++) {
        move_fireball();
        divide_fireball();
    }

    cout << get_total_m();

    return 0;
}