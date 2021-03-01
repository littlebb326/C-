#include <iostream>
using namespace std;
int space[101][101] = {0,};
void attach_paper(int a, int b);
int get_area();
int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        attach_paper(a,b);
    }
    cout << get_area();
    return 0;
}
void attach_paper(int a, int b) {
    for(int i=a+1;i<=a+10;i++) {
        for(int j=b+1;j<=b+10;j++){
            space[i][j] = 1;
        }
    }
}

int get_area() {
    int area = 0;
    for(int i=1;i<=100;i++) {
        for(int j=1;j<=100;j++) {
            area+=space[i][j];
        }
    }
    return area;
}