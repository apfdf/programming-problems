
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string name;
    cin >> name;
    
    int N;
    cin >> N;
    
    vector<string> names(N);
    for (int i = 0; i < N; i++) {
        cin >> names[i];
    }
    
    for (int i = 0; i < N; i++) {
        
        if (names[i].size() == name.size()) {
            
            int difs = 0;
            for (int j = 0; j < name.size(); j++) {
                if (name[j] != names[i][j]) {
                    difs++;
                }
            }
            
            if (difs == 1) {
                cout << i+1 << endl;
                return 0;
            }
            
        }
        
    }
    
    cout << N << endl;
    
}
