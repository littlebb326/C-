#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct customer
{
    int start_r, start_c, end_r, end_c, dist;
};
struct Edge {
    int r, c, cost;

    Edge(int _r, int _c, int _cost) {
        r = _r;
        c = _c;
        cost = _cost;
    }
};

int n, m, f;
int tx_r, tx_c;
int map[21][21];
int visit[21][21];
int dir[4][2] = {{0,1}, {0, -1}, {1,0}, {-1,0}};
int selected_idx;
vector<customer> customer_list;

bool compare(customer a, customer b) {
    if(a.start_r == b.start_r) {
        return a.start_c < b.start_c;
    }
    return a.start_r < b.start_r;
}

int get_distance(int start_r, int start_c, int end_r, int end_c) {
    queue<Edge> edge_q;
    edge_q.push(Edge(start_r, start_c, 0));
    for(int i=1;i<=20;i++) {
        for(int j=1;j<=20;j++){
            visit[i][j] = false;
        }
    }

    while(!edge_q.empty()) {
        Edge cur = edge_q.front();
        edge_q.pop();
        if(visit[cur.r][cur.c])
            continue;
        visit[cur.r][cur.c] = true;
        if(cur.r == end_r && cur.c == end_c)
            return cur.cost;
        for(int i=0;i<4;i++) {
            int next_r = dir[i][0] + cur.r;
            int next_c = dir[i][1] + cur.c;

            if(next_r > 0 && next_r <= n && next_c > 0 && next_c <= n) {
                if(map[next_r][next_c] == 0)
                    edge_q.push(Edge(next_r, next_c, cur.cost + 1));
            }
        }
    }
    return -1;
}
customer select_customer() {
    int min = 401;
    customer selected_customer;
    for(int i=0;i<customer_list.size();i++) {
        int dist = get_distance(tx_r, tx_c, customer_list[i].start_r, customer_list[i].start_c);
        if(dist < min) {
            min = dist;
            selected_customer = customer_list[i];
            selected_customer.dist = dist;
            selected_idx = i;
        }
    }
    return selected_customer;
}
int main() {
    cin >> n >> m >> f;
    customer selected_customer;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }
    cin >> tx_r >> tx_c;
    for(int i=0;i<m;i++) {
        customer c;
        cin >> c.start_r >> c.start_c >> c.end_r >> c.end_c;
        customer_list.push_back(c);
    }
    sort(customer_list.begin(), customer_list.end(), compare);
    for(int i=0;i<m;i++) {
        selected_customer = select_customer();
        if(selected_customer.dist == -1) {
            cout << -1;
            return 0;
        }
            
        tx_r = selected_customer.start_r;
        tx_c = selected_customer.start_c;
        int cost = selected_customer.dist;
        if(cost > f) {
            cout << -1;
            return 0;
        }
        f -= cost;
        cost = get_distance(tx_r, tx_c, selected_customer.end_r, selected_customer.end_c);
        if(cost > f) {
            cout << -1;
            return 0;
        }
        f += cost;
        tx_r = selected_customer.end_r;
        tx_c = selected_customer.end_c;

        customer_list.erase(customer_list.begin()+selected_idx);
    }

    cout << f;
    
    return 0;
}