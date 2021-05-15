#include <iostream>
using namespace std;
int main() {
    int arr[6] = {500, 100, 50, 10, 5, 1};
    int price, change;
    int cnt = 0;
    cin >> price;
    change = 1000 - price;
    
    for(int i=0;i<6;i++){
        while(arr[i] <= change){
            change -= arr[i];
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}