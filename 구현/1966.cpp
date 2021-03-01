#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n,m;
        int count = 1;
        cin >> n >> m;
        queue <int> priority;
        vector <int> sorted_priority;

        for(int j=0;j<n;j++) {
            int doc;
            cin >> doc;
            priority.push(doc);
            sorted_priority.push_back(doc);
        }

        sort(sorted_priority.begin(),sorted_priority.end());
        
        while(1) {
            if(priority.front() == sorted_priority.back())
            {
                if(m == 0) // target
                {
                    cout << count << endl;
                    break;
                }
                else {
                    sorted_priority.pop_back();
                    priority.pop();
                    m--;
                    count++;
                }
            }else {
                priority.push(priority.front());
                priority.pop();
                if(--m < 0)
                    m+=priority.size();
            }
        }

    }
    return 0;
}