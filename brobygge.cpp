
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(ll u, ll upper, vector<vector<ll>>& adj_list, vector<bool>& bottom, vector<bool>& top, bool* reached_bottom, bool* reached_top, vector<bool>& vis) {

    vis[u] = true;

    if (bottom[u]) {
        (*reached_bottom) = true;
    }
    if (top[u]) {
        (*reached_top) = true;
    }

    for (ll v : adj_list[u]) {
        if (!vis[v] && v <= upper) {
            dfs(v, upper, adj_list, bottom, top, reached_bottom, reached_top, vis);
        }
    }

}

bool upper_valid(ll upper, vector<vector<ll>>& adj_list, vector<bool>& bottom, vector<bool>& top) {

    bool valid = false;

    vector<bool> vis(adj_list.size());
    for (int i = 0; i <= upper; i++) {

        if (!vis[i]) {

            bool reached_bottom = false;
            bool reached_top = false;

            dfs(i, upper, adj_list, bottom, top, &reached_bottom, &reached_top, vis);

            if (reached_bottom && reached_top) {
                valid = true;
            }

        }

    }

    return valid;

}

int main() {
    
    ll N, M, T;
    cin >> N >> M >> T;
    
    vector<pair<ll, ll>> ordered_cells(T);
    for (int i = 0; i < T; i++) {
        cin >> ordered_cells[i].first >> ordered_cells[i].second;
    }

    map<pair<ll, ll>, ll> cells;
    for (int i = 0; i < T; i++) {
        cells[ordered_cells[i]] = i;
    }
    vector<vector<ll>> adj_list(T);
    for (int i = 0; i < T; i++) {
        ll r = ordered_cells[i].first;
        ll c = ordered_cells[i].second;
        if (cells.find({r+1, c}) != cells.end()) {
            adj_list[i].push_back(cells[{r+1, c}]);
        }
        if (cells.find({r-1, c}) != cells.end()) {
            adj_list[i].push_back(cells[{r-1, c}]);
        }
        if (cells.find({r, c+1}) != cells.end()) {
            adj_list[i].push_back(cells[{r, c+1}]);
        }
        if (cells.find({r, c-1}) != cells.end()) {
            adj_list[i].push_back(cells[{r, c-1}]);
        }
    }

    vector<bool> bottom(T);
    vector<bool> top(T);
    for (int i = 0; i < T; i++) {
        if (ordered_cells[i].first == 1) {
            bottom[i] = true;
        }
        if (ordered_cells[i].first == N-2) {
            top[i] = true;
        }
    }

    ll lo = 0;
    ll hi = T-1;

    while (lo != hi) {

        ll mid = (lo + hi) / 2;

        if (upper_valid(mid, adj_list, bottom, top)) {
            hi = mid;
        } else {
            lo = mid+1;
        }

    }

    if (upper_valid(lo, adj_list, bottom, top)) {
        cout << lo+1 << endl;
    } else {
        cout << "nej" << endl;
    }

}
