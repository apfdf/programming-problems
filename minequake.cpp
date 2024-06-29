
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// might need to change data type of mem to not exceed memory limit
ll dp(vector<vector<int>>& connections, int u, int v, int t, int rooms, vector<vector<pair<int, int>>>& mem) {

    if (mem[u][v].first != -1) {

        return mem[u][v].first + mem[u][v].second * t;

    }

    ll m = LLONG_MAX;

    for (int w : connections[v]) {
        if (w == u) {
            continue;
        }
        m = min(m, dp(connections, v, w, t+1, rooms+1, mem));
    }

    mem[u][v]

}
