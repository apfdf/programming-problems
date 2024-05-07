
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int> X(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }
    
    // have a list of max values from left to right and a list of
    // min values from right to left
    vector<bool> lr_max(n, false);
    int current_max = X[0];
    for (int i = 0; i < n; i++) {
        if (X[i] >= current_max) {
            current_max = X[i];
            lr_max[i] = true;
        }
    }
    vector<bool> rl_min(n, false);
    int current_min = X[n-1];
    for (int i = 0; i < n; i++) {
        if (X[n-1-i] < current_min) {
            current_min = X[n-1-i];
            rl_min[n-1-i] = true;
        }
    }
    
    int m = 0;
    vector<int> pivots = {};
    for (int i = 0; i < n; i++) {
        if (lr_max[i] && rl_min[i]) {
            pivots.insert(pivots.end(), X[i]);
            m++;
        }
    }

    cout << m;
    for (int i = 0; i < m; i++) {
        cout << " " << pivots[i];
    }
    cout << endl;
    
}
