
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int h, w;
    cin >> h >> w;
    
    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }
    
    float x_sum = 0;
    int tiles = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] != '.') {
                tiles++;
                x_sum += j + 0.5f;
            }
        }
    }
    
    float mean_x = x_sum / tiles;
    
    int left_most = 0;
    int right_most = 0;
    for (int j = 0; j < w; j++) {
        if (grid[h-1][j] != '.') {
            left_most = j;
            break;
        }
    }
    for (int j = w-1; j >= 0; j--) {
        if (grid[h-1][j] != '.') {
            right_most = j+1;
            break;
        }
    }
    
    if (mean_x < left_most) {
        cout << "left" << endl;
    } else if (mean_x > right_most) {
        cout << "right" << endl;
    } else {
        cout << "balanced" << endl;
    }
    
}
