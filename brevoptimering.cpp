
#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

void fill_graph(vector<vector<pair<int, int>>>& flipped, int i, vector<int>& M, vector<ld>& I, vector<ld>& U) {

    if (flipped[i].size() > 0) {

        for (int j = 0; j < flipped[i].size(); j++) {

            int other = flipped[i][j].first;

            if (U[other] == -1.0) {

                fill_graph(flipped, other, M, I, U);
                
            }

            I[i] += U[other] * ((ld)(flipped[i][j].second) / 100.0);

        }

    } else {

        U[i] = M[i];

    }

}

int main() {

    int N;
    cin >> N;

    vector<int> M(N);
    vector<ld> I(N);
    vector<ld> U(N, -1.0);

    vector<bool> root(N);

    vector<vector<pair<int, int>>> connections(N);
    vector<vector<pair<int, int>>> flipped(N);
    
    for (int i = 0; i < N; i++) {

        cin >> M[i];
        
        int k;
        cin >> k;

        for (int ii = 0; ii < k; ii++) {

            int j, w;
            cin >> j >> w;
            j--;

            connections[i].push_back({j, w});
            flipped[j].push_back({i, w});

        }

    }

    for (int i = 0; i < N; i++) {

        if (connections[i].size() == 0) {
            fill_graph(flipped, i, M, I, U);
        }

    }

    cout << " * ";
    for (int i = 0; i < N; i++) {
        cout << U[i] << " ";
    }
    cout << endl;

    vector<int> ans = {};

    for (int i = 0; i < N; i++) {
        if (abs(U[i] - M[i]) < 0.0001) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size()-1) {
            cout << " ";
        }
    }
    cout << endl;

}
