
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct station {
    ll d, x;
};

//dp(i) = sum(dp(j) for all j accessible from i), if none accessible dp(i) = 1, O(N)
//dp(i) should give mod 10^9 + 7
// transition is tricky
ll dp(int i, vector<station>& stations, vector<ll>& mem) {

    if (mem[i] != -1) {
        return mem[i];
    }

    if (i + stations[i].d >= stations.size() || stations[i].d == 0) {
        return 1;
    }

    ll s = 0;
    for (int t = 1; t <= stations[i].x; t++) {
        if (i + t*stations[i].d >= stations.size()) {
            break;
        }
        s += dp(i + t*stations[i].d, stations, mem);
    }

    mem[i] = s;
    return mem[i];

}

int main() {

    ll N;
    cin >> N;

    vector<station> stations(N);
    for (int i = 0; i < N; i++) {
        cin >> stations[i].d >> stations[i].x;
    }



}
