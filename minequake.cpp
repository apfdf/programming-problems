
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// first is node farthest away, second is distance
pair<int, int> farthest(vector<vector<int>>& connections, int u, int prev) {


    int m = 0;
    int w = u;
    for (int v : connections[u]) {
        if (v != prev) {
            
            pair<int, int> res = farthest(connections, v, u);
            if (m < res.second+1) {
                w = res.first;
                m = res.second+1;
            }
        }
    }

    return {w, m};

}

bool get_path(vector<vector<int>>& connections, int current, int target, int prev, vector<int>& path) {

    if (current == target) {
        path.push_back(current);
        return true;
    }

    for (int next : connections[current]) {
        if (next == prev) {
            continue;
        }
        if (get_path(connections, next, target, current, path)) {
            path.push_back(current);
            return true;
        }
    }

    return false;
    
}

ll sub(vector<vector<int>>& connections, int current, vector<bool>& vis, ll& t) {

    ll res = t;
    vis[current] = true;

    for (int next : connections[current]) {
        if (!vis[next]) {
            cout << "should not happen" << endl;
            t++;
            res += sub(connections, next, vis, t);
            t++;
        }
    }

    return res;

}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> connections(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        connections[u].push_back(v);
        connections[v].push_back(u);
    }

    // find a diameter of the tree
    int l1 = farthest(connections, 0, -1).first;
    int l2 = farthest(connections, l1, -1).first;

    vector<int> path = {};
    get_path(connections, l1, l2, -1, path);

    vector<bool> vis(n);
    for (int u : path) {
        vis[u] = true;
    }

    ll ans = 0;

    ll t = 0;
    for (int u : path) {
        ans += t;
        for (int v : connections[u]) {
            if (!vis[v]) {
                t++;
                ans += sub(connections, v, vis, t);
                t++;
            }
        }
        t++;
    }

    cout << ans << endl;

}
