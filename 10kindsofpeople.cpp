
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<vector<bool>>& grid, vector<vector<int>>& grid_signs, int sign, int i, int j) {
    
    grid_signs[i][j] = sign;

    int h = grid.size();
    int w = grid[0].size();
    
    if (i > 0) {
        if (!grid_signs[i-1][j] && grid[i][j] == grid[i-1][j]) {
            dfs(grid, grid_signs, sign, i-1, j);
        }
    }
    if (i < h-1) {
        if (!grid_signs[i+1][j] && grid[i][j] == grid[i+1][j]) {
            dfs(grid, grid_signs, sign, i+1, j);
        }
    }
    if (j > 0) {
        if (!grid_signs[i][j-1] && grid[i][j] == grid[i][j-1]) {
            dfs(grid, grid_signs, sign, i, j-1);
        }
    }
    if (j < w-1) {
        if (!grid_signs[i][j+1] && grid[i][j] == grid[i][j+1]) {
            dfs(grid, grid_signs, sign, i, j+1);
        }
    }
    
}

int main() {
    
    int r, c;
    cin >> r >> c;
    
    vector<vector<bool>> grid(r, vector<bool>(c));
    for (int i = 0; i < r; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < c; j++) {
            grid[i][j] = (row[j] == '1');
        }
    }
    
    int n;
    cin >> n;

    vector<vector<int>> grid_signs(r, vector<int>(c, 0));
    int current_sign = 1;

    for (int i = 0; i < n; i++) {
        
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        
        if (grid[r1][c1] == grid[r2][c2]) {
            if (grid_signs[r1][c1] == 0 && grid_signs[r2][c2] == 0) {
                dfs(grid, grid_signs, current_sign, r1, c1);
                current_sign++;
            }
            if (grid_signs[r1][c1] == grid_signs[r2][c2]) {
                if (grid[r1][c1]) {
                    cout << "decimal";
                } else {
                    cout << "binary";
                }
            } else {
                cout << "neither";
            }
        } else {
            cout << "neither";
        }

        cout << endl;

    }
    
}
