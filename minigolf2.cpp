
#include <bits/stdc++.h>
using namespace std;

int main() {

    int R, C, K;
    cin >> R >> C >> K;

    vector<string> grid(R);
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }

    // BFS? kan bli O(R*C), behöver aldrig gå tillbaka till besökta

    // behöver ett sätt att begränsa antalet rutor man kollar. Väggar och vis borde begränsa, ger O(R*C) (kollar inte samma ruta två gånger)

    vector<vector<bool>> vis(R, vector<bool>(C));
    vector<vector<bool>> vis_vert(R, vector<bool>(C));
    vector<vector<bool>> vis_hori(R, vector<bool>(C));

    vector<pair<int, int>> layer = {};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'S') {
                layer.push_back({i, j});
            }
        }
    }

    pair<int, int> start;
    pair<int, int> goal;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            }
            if (grid[i][j] == 'G') {
                goal = {i, j};
            }
        }
    }

    vis[start.first][start.second] = true;
    vis_vert[start.first][start.second] = true;
    vis_hori[start.first][start.second] = true;

    int round = 0;

    while (layer.size() > 0) {

        if (vis[goal.first][goal.second]) {
            cout << round << endl;
            break;
        }

        vector<pair<int, int>> new_layer = {};

        vector<pair<int, int>> layer_vert = layer;
        vector<pair<int, int>> layer_hori = layer;

        sort(layer_vert.begin(), layer_vert.end(), [](pair<int, int> p1, pair<int, int> p2) {return p1.first < p2.first;});
        sort(layer_hori.begin(), layer_hori.end(), [](pair<int, int> p1, pair<int, int> p2) {return p1.second < p2.second;});

        round++;

        for (int i = 0; i < layer.size(); i++) {

            int r = layer_vert[layer.size()-1-i].first;
            int c = layer_vert[layer.size()-1-i].second;

            for (int j = 1; j < K+1; j++) {

                if (r + j >= R) {
                    break;
                }

                if (grid[r+j][c] != '#' && !vis_vert[r+j][c]) {
                    if (!vis[r+j][c]) {
                        new_layer.push_back({r+j, c});
                    }
                    vis[r+j][c] = true;
                    vis_vert[r+j][c] = true;
                } else {
                    break;
                }

            }

        }

        for (int i = 0; i < layer.size(); i++) {

            int r = layer_vert[i].first;
            int c = layer_vert[i].second;

            for (int j = 1; j < K+1; j++) {

                if (r - j < 0) {
                    break;
                }

                if (grid[r-j][c] != '#' && !vis_vert[r-j][c]) {
                    if (!vis[r-j][c]) {
                        new_layer.push_back({r-j, c});
                    }
                    vis[r-j][c] = true;
                    vis_vert[r-j][c] = true;
                } else {
                    break;
                }

            }
        
        }

        for (int i = 0; i < layer.size(); i++) {

            int r = layer_hori[layer.size()-1-i].first;
            int c = layer_hori[layer.size()-1-i].second;

            for (int j = 1; j < K+1; j++) {

                if (c + j >= C) {
                    break;
                }

                if (grid[r][c+j] != '#' && !vis_hori[r][c+j]) {
                    if (!vis[r][c+j]) {
                        new_layer.push_back({r, c+j});
                    }
                    vis[r][c+j] = true;
                    vis_hori[r][c+j] = true;
                } else {
                    break;
                }

            }
        
        }

        for (int i = 0; i < layer.size(); i++) {

            int r = layer_hori[i].first;
            int c = layer_hori[i].second;

            for (int j = 1; j < K+1; j++) {

                if (c - j < 0) {
                    break;
                }

                if (grid[r][c-j] != '#' && !vis_hori[r][c-j]) {
                    if (!vis[r][c-j]) {
                        new_layer.push_back({r, c-j});
                    }
                    vis[r][c-j] = true;
                    vis_hori[r][c-j] = true;
                } else {
                    break;
                }

            }

        }

        layer = new_layer;

    }

}
