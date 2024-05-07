
// DIJKSTRA MED PRIORITY QUEUE!!!

// kan göras bättre med heap istället för binary search tree, worst case av O(N) blir O(log N) (NICE!!!)

#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<pair<int, int>>> connections = {
        {{1, 3}, {2, 3}, {3, 2}},
        {{0, 3}, {2, 1}},
        {{1, 1}, {0, 3}},
        {{0, 2}}
    };

    vector<int> prev(connections.size(), -1);
    vector<int> dist(connections.size(), INT_MAX);
    dist[0] = 0;

    set<int, function<bool(int, int)>> queue([dist](int u, int v) {return dist[u] < dist[v];});
    for (int i = 0; i < connections.size(); i++) {
        queue.insert(i);
    }

    while (!queue.empty()) {

        int u = *queue.begin();
        queue.erase(u);

        for (int i = 0; i < connections[u].size(); i++) {

            int v = connections[u][i].first;
            int d = connections[u][i].second;

            if (dist[u] + d < dist[v]) {

                queue.erase(v);

                dist[v] = dist[u] + d;
                prev[v] = u;

                queue.insert(v);

            }

        }

    }

    for (int i = 0; i < connections.size(); i++) {
        cout << dist[i] << endl;
    }

}
