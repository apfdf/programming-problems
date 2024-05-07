
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dfs(vector<vector<pair<ll, ll>>>& connections, ll current, ll prev) {

    ll m = 0;
    for (int i = 0; i < connections[current].size(); i++) {
        if (connections[current][i].first == prev) {
            continue;
        }
        ll res = connections[current][i].second + dfs(connections, connections[current][i].first, current);
        if (res > m) {
            m = res;
        }
    }

    return m;

}

int main() {
    
    ll N, k;
    cin >> N >> k;
    
    vector<vector<pair<ll, ll>>> connections(N);
    ll s = 0;
    for (int i = 0; i < N-1; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        connections[u].push_back({v, c});
        connections[v].push_back({u, c});
        s += c;
    }
    
    if (k > 1) {

        cout << s << endl;

    } else {

        cout << dfs(connections, N-1, -1) << endl;

    }
    
}
