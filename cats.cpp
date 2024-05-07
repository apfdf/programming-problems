
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {

        ll M, C;
        cin >> M >> C;
        
        vector<vector<int>> dist(C, vector<int>(C));
        vector<array<int, 3>> inp((C*(C-1)) / 2);
        for (int i = 0; i < (C*(C-1))/2; i++) {
            
            int v1, v2, d;
            cin >> v1 >> v2 >> d;
            dist[v1][v2] = d;
            dist[v2][v1] = d;

            inp[i] = {v1, v2, d};
            
        }
    
        // idea: store edges in a set, start from node 0 and add edges to the queue.
        // always pick the shortest edges that lead to a new node
        
        set<pair<int, int>, function<bool(pair<int, int>, pair<int, int>)>> edge_queue(
            [dist](pair<int, int> p1, pair<int, int> p2) {
                return dist[p1.first][p1.second] < dist[p2.first][p2.second];
            }
        );

        ll tot_weight = 0;

        vector<bool> vis(C);
        vis[0] = true;
        int added_node = 0;
        for (int i = 0; i < C-1; i++) {

            for (int j = 0; j < C; j++) {
                if (j == added_node) {
                    continue;
                }
                edge_queue.insert({added_node, j});
            }

            while (true) {
    
                pair<int, int> top = *edge_queue.begin();

                edge_queue.erase(top);

                int src = top.first;
                int dst = top.second;

                if (!vis[dst]) {
                    tot_weight += dist[src][dst];
                    added_node = dst;
                    vis[dst] = true;
                    break;
                }

            }
            

        }

        if (M - tot_weight >= C) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

    }
    
}
