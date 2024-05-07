
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp(ll i, vector<array<ll, 3>>& trips, vector<array<ll, 2>>& stations, vector<ll>& mem) {

    if (mem[i] != -1) {
        return mem[i];
    }

    ll m = 0;
    for (int j = i+1; j < trips.size(); j++) {

        ll dt = trips[j][0] - trips[i][0];
        ll dist = abs(stations[trips[j][2]][0] - stations[trips[i][2]][0]) + abs(stations[trips[j][2]][1] - stations[trips[i][2]][1]);

        if (dist <= dt) {
            ll res = dp(j, trips, stations, mem);
            if (res > m) {
                m = res;
            }
        }

    }

    mem[i] = trips[i][1] + m;
    return mem[i];

}

int main() {

    ll N;
    cin >> N;

    ll unused_index = 0;
    map<array<ll, 2>, ll> cts;
    map<ll, array<ll, 2>> stc;
    vector<array<ll, 3>> trips(N);


    for (int i = 0; i < N; i++) {

        ll t, s, x, y;
        cin >> t >> s >> x >> y;

        if (cts.find({x, y}) == cts.end()) {
            cts[{x, y}] = unused_index;
            stc[unused_index] = {x, y};
            unused_index++;
        }

        trips[i] = {t, s, cts[{x, y}]};

    }

    vector<array<ll, 2>> stations(cts.size());
    for (int i = 0; i < cts.size(); i++) {
        stations[i] = stc[i];
    }

    sort(trips.begin(), trips.end(), [](array<ll, 3> t1, array<ll, 3> t2) {return t1[0] < t2[0];});

    vector<ll> mem(N, -1);

    // choose maximum result of dp depending on what trip is start
    ll m = 0;
    for (int i = 0; i < N; i++) {
        ll res = dp(i, trips, stations, mem);
        if (res > m) {
            m = res;
        }
    }

    cout << m << endl;

}
