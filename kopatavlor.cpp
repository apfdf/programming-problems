
#include <bits/stdc++.h>
using namespace std;

/*
int dp(int i, int k, vector<int>& T, vector<vector<int>> mem) {

    if (k == 0) {
        return 0;
    }
    if (i == T.size()) {
        return 4000000;
    }

    if (mem[i][k] != -1) {
        return mem[i][k];
    }

    if (k == 1) {
        mem[i][k] = min(T[i], 1 + dp(i+1, k, T, mem));
    } else {
        mem[i][k] = 1 + min(dp(i+1, k, T, mem), T[i] + dp(i+1, k-1, T, mem));
    }

    return mem[i][k];

}
*/

int dp(int i, int k, vector<int>& T, vector<vector<int>>& mem) {

    if (k == 0) {
        return 0;
    }
    if (i == T.size()) {
        return -1;
    }

    if (mem[i][k] != -1) {
        return mem[i][k];
    }

    if (k == 1) {

        int r1 = T[i];
        int r2 = dp(i+1, k, T, mem);
        
        if (r2 == -1) {
            mem[i][k] = r2+1;
        } else {
            mem[i][k] = min(r1, r2+1);
        }

    } else {

        int r1 = dp(i+1, k, T, mem);
        int r2 = dp(i+1, k-1, T, mem);
        
        if (r1 == -1) {
            mem[i][k] = T[i] + 1 + r2;
        } else if (r2 == -1) {
            mem[i][k] = 1 + r1;
        } else {
            mem[i][k] = min(1 + r1, T[i] + 1 + r2);
        }

    }

    return mem[i][k];

}

int main() {

    int N, k;
    cin >> N >> k;

    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    vector<vector<int>> mem(N, vector<int>(N, -1));

    int ans = -1;
    for (int i = 0; i < N; i++) {
        int res = dp(i, k, T, mem);
        if (ans == -1 || (res != -1 && res < ans)) {
            ans = res;
        }
    }

    cout << ans << endl;

}
