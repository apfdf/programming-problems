
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp(vector<pair<int, int>>& vecs, int i, int x, int y, vector<vector<vector<ll>>>& mem) {
    
    if (i == vecs.size()) {
        return (x == 0 && y == 0);
    }

    if (mem[i][x+40*10][y+40*10] != -1) {
        return mem[i][x+40*10][y+40*10];
    }
    
    mem[i][x+40*10][y+40*10] = dp(vecs, i+1, x + vecs[i].first, y + vecs[i].second, mem) + dp(vecs, i+1, x, y, mem);
    return mem[i][x+40*10][y+40*10];
    
}

int main() {
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> vecs(N);
    for (int i = 0; i < N; i++) {
        cin >> vecs[i].first >> vecs[i].second;
    }
    
    vector<vector<vector<ll>>> mem(N, vector<vector<ll>>(80*10, vector<ll>(80*10, -1)));
    ll res = dp(vecs, 0, 0, 0, mem) - 1;
    
    cout << res << endl;

}
