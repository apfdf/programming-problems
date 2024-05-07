
#include <bits/stdc++.h>
using namespace std;

int dp(vector<int>& D, vector<int>& R, vector<int>& G, vector<int>& P, int p, bool work, vector<vector<int>>& mem, int& count) {

    if (mem[p][work] != -1) {
        return mem[p][work];
    }

    count++;
    if (count > 3 * (D.size() + R.size())) {
        cout << "wrong" << endl;
    }

    int p1 = p;

    int res_grand = INT_MAX;

    for (int i = 0; i < G.size(); i++) {

        int res;

        int cost = P[i];
        if (work) {
            cost /= 2;
        }

        int day = ((work) ? R[p] : D[p]) + G[i] - 1;

        int lo = 0;
        int hi = D.size()-1;

        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (D[mid] > day) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        int next = lo;

        if (D[next] > day) {

            res = cost + dp(D, R, G, P, next, false, mem, count);

            if (R.size() > 0) {

                lo = 0;
                hi = R.size()-1;

                while (lo != hi) {
                    int mid = (lo + hi) / 2;
                    if (R[mid] <= D[next]) {
                        lo = mid;
                    } else {
                        hi = mid-1;
                    }
                }

                if (R[lo] > ((work) ? R[p] : D[p]) && R[lo] <= D[next]) {
                    res = min(res, cost + dp(D, R, G, P, lo, true, mem, count));
                }

            }

        } else {
            res = cost;
        }

        res_grand = min(res_grand, res);

    }

    mem[p][work] = res_grand;
    return mem[p][work];

}

int main() {

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }
    vector<int> G(M);
    for (int i = 0; i < M; i++) {
        cin >> G[i];
    }
    vector<int> P(M);
    for (int i = 0; i < M; i++) {
        cin >> P[i];
    }
    sort(G.begin(), G.end());
    sort(P.begin(), P.end());
    vector<int> R(K);
    for (int i = 0; i < K; i++) {
        cin >> R[i];
    }

    sort(D.begin(), D.end());
    sort(R.begin(), R.end());

    vector<vector<int>> mem(max(N, K), vector<int>(2, -1));

    int count = 0;

    int ans = dp(D, R, G, P, 0, false, mem, count);
    if (K > 0) {
        int R_start = 0;
        for (int i = 0; i < K; i++) {
            if (R[i] <= D[0]) {
                R_start = i;
            }
        }
        if (R[R_start] <= D[0]) {
            ans = min(ans, dp(D, R, G, P, R_start, true, mem, count));
        }
    }

    cout << ans << endl;

}
