
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int p, w;
    cin >> p >> w;
    
    int cells_filled = floor(((float)p / 100) * w);
    cout << "[";
    for (int i = 0; i < w; i++) {
        if (i < cells_filled) {
            cout << "#";
        } else {
            cout << "-";
        }
    }
    cout << "] | ";
    
    if (p < 100) {
        cout << " ";
    }
    if (p < 10) {
        cout << " ";
    }
    cout << p << "%" << endl;

}
