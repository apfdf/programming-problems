
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> specials(K);
    for (int i = 0; i < K; i++)
        cin >> specials[i];
    
    vector<vector<int>> connections(N);
    for (int i = 0; i < N; i++) {
        connections[i] = {};
    }
    for (int i = 0; i < N-1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        connections[v1-1].push_back(v2);
        connections[v2-1].push_back(v1);
    }

    vector<bool> node_map(true, N);

    for (int i = 0; i < N; i++) {
        
        int current = i+1;
        while (node_map[current-1]) {
            int deg = 0;
            for (int j = 0; j < connections[current-1].size(); j++) {
                if (node_map[connections[current-1][j]-1]) {
                    deg++;
                }
            }
            if (deg == 1 && current != 1 && count(specials.begin(), specials.end(), current) == 0) {
                node_map[current-1] = false;
                int connected_to;
                for (int j = 0; j < connections[current-1].size(); j++) {
                    if (node_map[connections[current-1][j]-1]) {
                        connected_to = connections[current-1][j];
                    }
                }
                current = connected_to;
            } else {
                break;
            }
        }
    }

    int nodes_left = 0;
    for (int i = 0; i < N; i++) {
        if (node_map[i]) {
            nodes_left++;
        }
    }

    int ans = (nodes_left-1) * 2;

    cout << ans << endl;

}
