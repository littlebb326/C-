#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int max_val = 0;
    int array[10] = {0,};
    cin >> n;
    if(n == 0) {
        cout << 1;
        return 0;
    } else {
        while(n > 0) {
            array[n%10]++;
            n /= 10;      
        }
        if((array[6] + array[9]) % 2 == 1)
            array[6] = (array[6] + array[9] + 1) / 2;
        else
            array[6] = (array[6] + array[9]) / 2;
        for(int i=0;i<=8;i++){
            max_val = max(max_val,array[i]);
        }
    }
    cout << max_val;
    return 0;
}