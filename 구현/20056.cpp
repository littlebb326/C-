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
vector<Fireball> v;
int get_position(int p) {
    cout << "p : " << p << " -> ";
    if(p > n) {
        cout << p%n << endl;
        return p % n;
    }
    else if(p <= 0) {
        int temp = abs(p) / n;
        cout << p + ((temp + 1) * n) << endl;
        return p + ((temp + 1) * n);
    }
    else {
        cout << p << endl;
        return p;
    }
}
void move_fireball() {

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=map[i][j].size()-1;k>=0;k--) {
                Fireball fb = map[i][j][k];
                fb.r = get_position(fb.r + (dir[fb.d][0] * fb.s));
                fb.c = get_position(fb.c + (dir[fb.d][1] * fb.s));
                map[fb.r][fb.c].push_back(fb);
                map[i][j].pop_back();
            }
        }
    }

    // for(int i=0;i<v.size();i++) {
    //     map[v[i].r][v[i].c]--;
    //     v[i].r = get_position(v[i].r + (dir[v[i].d][0] * v[i].s));
    //     v[i].c = get_position(v[i].c + (dir[v[i].d][1] * v[i].s));
    //     map[v[i].r][v[i].c]++;
    // }
}
void print() {
    cout << "### fire ball ###" << endl;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=map[i][j].size()-1;k>=0;k--) {
                Fireball fb = map[i][j][k];
                cout << fb.r << ' ' << fb.c << ' ' << fb.m << ' ' << fb.s << ' ' << fb.d << endl;
            }
        }
    }
    // cout << "### count map ###" << endl;
    // for(int i=0;i<v.size();i++)
    //     cout << v[i].r << ' ' << v[i].c << ' ' << v[i].m << ' ' << v[i].s << ' ' << v[i].d << endl;
    // cout << "### count map ###" << endl;
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}
int main() {

    cin >> n >> m >> k;
    for(int i=0;i<m;i++) {
        Fireball fb;
        cin >> fb.r >> fb.c >> fb.m >> fb.s >> fb.d;
        map[fb.r][fb.c].push_back(fb);
    }
    //print();
    for(int i=0;i<k;i++) {
        move_fireball();
        print();
    }

    return 0;
}