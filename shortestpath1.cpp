
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
    int v, w;
};

int main() {
    
    int t = 0;

    while (true) {

        int n, m, q, s;
        cin >> n >> m >> q >> s;

        if (n == 0 && m == 0 && q == 0 && s == 0) {
            break;
        }

        if (t != 0) {
            cout << endl;
        }
        
        vector<vector<edge>> alist(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            alist[u].push_back({v, w});
        }
        
        vector<ll> dist(n, LLONG_MAX);
        dist[s] = 0;
        
        multiset<int, function<bool(int, int)>> queue([dist](int u, int v) {return dist[u] < dist[v];});
        for (int i = 0; i < n; i++) {
            queue.insert(i);
        }

        while (!queue.empty()) {

            int u = *queue.begin();
            queue.erase(queue.begin());

            if (dist[u] == LLONG_MAX) {
                break;
            }

            for (int i = 0; i < alist[u].size(); i++) {

                int v = alist[u][i].v;
                int w = alist[u][i].w;

                if (dist[v] > dist[u] + w) {

                    queue.erase(v);
                    dist[v] = dist[u] + w;
                    queue.insert(v);

                }

            }

        }

        for (int i = 0; i < q; i++) {

            int u;
            cin >> u;

            if (dist[u] == LLONG_MAX) {
                cout << "impossible" << endl;
            } else {
                cout << dist[u] << endl;
            }

        }

        t++;

    }

}
