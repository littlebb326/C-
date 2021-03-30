#include <iostream>
#include <vector>
using namespace std;
struct square {
    int dur;
    bool isRobot = false;
};
square belt[201];
int up_idx = 1;
int down_idx;
int n, k;
int total_zero_cnt = 0;
int progress_cnt = 0;
void push_robot() {
    if(!belt[up_idx].isRobot && belt[up_idx].dur >= 1) {
        belt[up_idx].isRobot = true;
        belt[up_idx].dur--;
        if(belt[up_idx].dur == 0) {
            total_zero_cnt++;
        }
    }
}
void move_robot() {
    int idx = down_idx;
    while(idx != up_idx) {
        int next_belt_idx = idx == (2*n) ? 1 : (idx+1);
        if(belt[idx].isRobot && !belt[next_belt_idx].isRobot && belt[next_belt_idx].dur >= 1) {
            belt[idx].isRobot = false;
            belt[next_belt_idx].isRobot = true;
            belt[next_belt_idx].dur--;
            if(belt[next_belt_idx].dur == 0) {
                total_zero_cnt++;
            }
            if(belt[down_idx].isRobot) {
                belt[down_idx].isRobot = false;
            }
        }
        idx--;
        if(idx == 0)
            idx = 2*n;
    }
}
void rotate_belt() {
    up_idx--;
    down_idx--;
    if(up_idx == 0)
        up_idx = 2*n;
    if(down_idx == 0)
        down_idx = 2*n;
    if(belt[down_idx].isRobot) {
        belt[down_idx].isRobot = false;
    }
}
void move_conveyor_belt() {
    progress_cnt++;
    rotate_belt();
    move_robot();
    push_robot();
}
int main() {

    cin >> n >> k;
    down_idx = n;
    for(int i=1;i<=2*n;i++) {
        cin >> belt[i].dur;
    }
    while(total_zero_cnt < k) {
        move_conveyor_belt();
    }
    cout << progress_cnt;
    return 0;
}