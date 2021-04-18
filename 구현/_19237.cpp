#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct shark
{
    int r, c;
    int number, dir;
    int dir_prior[5][5];
};
struct smell
{
    int shark_num = 0;
    int duration = 0;
};
int n, m, k;
int dir_xy[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int map[21][21];
smell smell_map[21][21];
vector<shark> shark_list;

bool compare(shark s1, shark s2) {
    return s1.number < s2.number;
}
void init_map() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            map[i][j] = 0;
        }
    }
}
void reduce_duration() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(smell_map[i][j].duration > 0) {
                smell_map[i][j].duration--;
                if(smell_map[i][j].duration == 0)
                    smell_map[i][j].shark_num = 0;
            }
        }
    }
}
void release_smell() {
    for(int i=0;i<shark_list.size();i++) {
        shark s = shark_list[i];
        smell_map[s.r][s.c].shark_num = s.number;
        smell_map[s.r][s.c].duration = k;
    }
}
void move_shark() {
    init_map();
    vector<int> erased_list;
    for(int i=0;i<shark_list.size();i++) {
        int this_shark_num = shark_list[i].number;
        bool is_find = false;
        int find_r, find_c, find_dir;

        for(int j=1;j<=4;j++) {
            int next_dir = shark_list[i].dir_prior[shark_list[i].dir][j];
            int next_r = shark_list[i].r + dir_xy[next_dir][0];
            int next_c = shark_list[i].c + dir_xy[next_dir][1];
            if(smell_map[next_r][next_c].duration == 0) {
                if(next_r > 0 && next_r <= n && next_c > 0 && next_c <= n) {
                    find_r = next_r;
                    find_c = next_c;
                    find_dir = next_dir;
                    is_find = true;
                    break;
                }
            }
        }
        if(!is_find) {
            for(int j=1;j<=4;j++) {
                int next_dir = shark_list[i].dir_prior[shark_list[i].dir][j];
                int next_r = shark_list[i].r + dir_xy[next_dir][0];
                int next_c = shark_list[i].c + dir_xy[next_dir][1];
                if(smell_map[next_r][next_c].shark_num == this_shark_num) {
                    if(next_r > 0 && next_r <= n && next_c > 0 && next_c <= n) {
                        find_r = next_r;
                        find_c = next_c;
                        find_dir = next_dir;
                        is_find = true;
                        break;
                    }
                }
            }
        }

        cout << this_shark_num << " shark <" << find_r << " ," << find_c << '>' << " dir : " << find_dir << endl;

        if(map[find_r][find_c] == 0) {
            cout << this_shark_num << " is moved" << endl;
            shark_list[i].r = find_r;
            shark_list[i].c = find_c;
            shark_list[i].dir = find_dir;
            map[find_r][find_c] = this_shark_num;
        }
        else {
            cout << this_shark_num << " shark erased..." << endl;
            erased_list.push_back(this_shark_num);
            //shark_list.erase(shark_list.begin() + this_shark_num - 1);
        }
    }
    for(int i=0;i<erased_list.size();i++) {
        int erased_cnt = 0;
        shark_list.erase(shark_list.begin() + erased_list[i] - erased_cnt)
    }
    reduce_duration();
    release_smell();
}
void print() {
    cout << "#### shark list ####" << endl;
    for(int i=0;i<shark_list.size();i++) {
        shark s = shark_list[i];
        cout << "shark " << s.number << endl;
        cout << '<' << s.r << ", " << s.c << '>' << " dir : " << s.dir << endl;
    }
}
int main() {
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> map[i][j];
            if(map[i][j] != 0) {
                shark s;
                s.r = i;
                s.c = j;
                s.number = map[i][j];
                shark_list.push_back(s);
                smell_map[i][j].shark_num = map[i][j];
                smell_map[i][j].duration = k;
            }
        }
    }
    sort(shark_list.begin(),shark_list.end(),compare);
    for(int i=0;i<m;i++)
        cin >> shark_list[i].dir;
    for(int i=0;i<m;i++) {
        for(int j=1;j<=4;j++) {
            for(int k=1;k<=4;k++) {
                cin >> shark_list[i].dir_prior[j][k];
            }
        }
    }
    move_shark();
    // for(int i=0;i<shark_list.size();i++) {
    //     shark s = shark_list[i];
    //     cout << s.number << " shark : " << s.r << ' ' << s.c << endl;
    //     for(int j=1;j<=4;j++) {
    //         for(int k=1;k<=4;k++) {
    //             cout << s.dir_prior[j][k] << ' '; 
    //         }
    //         cout << endl;
    //     }
    // }



    

    return 0;
}