
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    for (int t = 0; t < n; t++) {
        
        int m, p;
        cin >> m >> p;
        
        vector<int> bgns(100);
        vector<int> ends(100);
        
        for (int i = 0; i < m; i++) {
            int b, e;
            cin >> b >> e;
            bgns[b-1]++;
            ends[e-1]++;
        }
        
        int tot_completed = 0;
        int tot_ends = 0;
        int ongoing = 0;
        
        bool possible = true;
        
        for (int i = 0; i < 100; i++) {
            
            ongoing += bgns[i];
            tot_completed += min(ongoing, p/2);
            ongoing = max(0, ongoing - p/2);
            
            tot_ends += ends[i];
            
            if (tot_ends > tot_completed) {
                possible = false;
                break;
            }
            
        }
        
        if (!possible) {
            cout << "serious trouble" << endl;
            continue;
        }
        
        tot_completed = 0;
        tot_ends = 0;
        ongoing = 0;
        
        possible = true;
        
        for (int i = 0; i < 100; i++) {
            
            ongoing += bgns[i];
            
            if (i % 7 < 5) {
                tot_completed += min(ongoing, p/2);
                ongoing = max(0, ongoing - p/2);
            }
            
            tot_ends += ends[i];
            
            if (tot_ends > tot_completed) {
                possible = false;
                break;
            }
            
        }
        
        if (possible) {
            cout << "fine" << endl;
        } else {
            cout << "weekend work" << endl;
        }

    }
    
}
