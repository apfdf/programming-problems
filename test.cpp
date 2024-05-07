
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, m;
    cin >> m >> n;
    
    int cells = n*m;
    int empty_cells = 0;
    for (int i = 0; i < n; i++) {
        string lane;
        cin >> lane;
        for (int j = 0; j < m; j++) {
            if (lane[j] == '.') {
                empty_cells++;
            }
        }
    }
    
    cout << (float)empty_cells / (float)cells << endl;
    
}
