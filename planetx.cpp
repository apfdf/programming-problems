
#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {

        string row;
        cin >> row;

        for (int j = 0; j < M; j++) {
            grid[i][j] = (row[j] != '.') ? (int)(row[j] - '0') : -1;
        }

    }

    vector<pair<int, int>> known = {};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] != -1) {
                known.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < known.size(); i++) {

        int possible_squares = 0;
        pair<int, int> last_corner;

        for (int j = 0; j < known.size(); j++) {

            if (i == j) {
                continue;
            }

            if (abs(known[i].first - known[j].first) + abs(known[i].second - known[j].second) == abs(grid[known[i].first][known[i].second] - grid[known[j].first][known[j].second])) {

                int sr = known[i].first;
                int sc = known[i].second;
                int tr = known[j].first;
                int tc = known[j].second;

                pair<int, int> top_left = {min(sr, tr), min(sc, tc)};
                pair<int, int> bottom_right = {max(sr, tr), max(sc, tc)};

                int d_sign = (grid[tr][tc] - grid[sr][sc]) / abs(grid[tr][tc] - grid[sr][sc]);

                for (int r = top_left.first; r < bottom_right.first+1; r++) {
                    for (int c = top_left.second; c < bottom_right.second+1; c++) {

                        int dist = abs(r - sr) + abs(c - sc);
                        grid[r][c] = grid[sr][sc] + dist * d_sign;

                    }
                }

            }

        }

        // if (possible_squares == 1) {

        //     int sr = known[i].first;
        //     int sc = known[i].second;
        //     int tr = last_corner.first;
        //     int tc = last_corner.second;

        //     pair<int, int> top_left = {min(sr, tr), min(sc, tc)};
        //     pair<int, int> bottom_right = {max(sr, tr), max(sc, tc)};

        //     int d_sign = (grid[tr][tc] - grid[known[i].first][known[i].second]) / abs(grid[tr][tc] - grid[known[i].first][known[i].second]);

        //     for (int r = top_left.first; r < bottom_right.first+1; r++) {
        //         for (int c = top_left.second; c < bottom_right.second+1; c++) {

        //             if (grid[r][c] != -1) {
        //                 continue;
        //             }

        //             int dist = abs(r - sr) + abs(c - sc);
        //             grid[r][c] = grid[sr][sc] + dist * d_sign;

        //         }
        //     }

        // }

    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == -1) {
                cout << ".";
            } else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }

    // vector<vector<bool>> vis(N, vector<bool>(M));

    // for (int i = 0; i < known.size(); i++) {

    //     int max_dist = 0;

    //     int r1 = known[i].first;
    //     int c1 = known[i].second;

    //     for (int j = 0; j < known.size(); j++) {

    //         if (i == j) {
    //             continue;
    //         }

    //         int r2 =  known[known.size()-1-j].first;
    //         int c2 =  known[known.size()-1-j].second;            

    //         if (abs(r1 - r2) + abs(c1 - c2) == abs(grid[r1][c1] - grid[r2][c2])) {
    //             if (abs(r1 - r2) + abs(c1 - c2) > max_dist)
    //         }

    //     }

    // }

}
