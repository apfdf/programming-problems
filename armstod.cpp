
#include <bits/stdc++.h>
using namespace std;

int max_satisfied(string& pref, int i, bool placed_last, bool placed_first, vector<array<array<int, 2>, 2>>& mem) {

    if (mem[i][placed_last][placed_first] != -1) {
        return mem[i][placed_last][placed_first];
    }

    if (i == pref.size()-1) {

        int k1 = 0;
        int k2 = 0;

        if (placed_last) {
            if (pref[i] == 'V' || pref[i] == 'A') {
                k1++;
            } else if (pref[i] == 'B') {
                k2++;
            }
        } else {
            if (pref[i] == 'H' || pref[i] == 'A') {
                k1++;
            } else if (pref[i] == 'I') {
                k2++;
            }
        }

        mem[i][placed_last][placed_first] = (placed_last) ? k1 : k2;
        return mem[i][placed_last][placed_first];

    }

    int k1 = 0;
    int k2 = 0;

    if (i != 0) {

        if (placed_last) {
            if (pref[i] == 'V' || pref[i] == 'A') {
                k2++;
            } else if (pref[i] == 'B') {
                k1++;
            }
        } else {
            if (pref[i] == 'H' || pref[i] == 'A') {
                k1++;
            } else if (pref[i] == 'I') {
                k2++;
            }
        }

    }

    if (i == pref.size()-1) {



    }

    int res = max(k1 + max_satisfied(pref, i+1, true, placed_first, mem), k2 + max_satisfied(pref, i+1, false, placed_first, mem));
    mem[i][placed_last][placed_first] = res;

    return mem[i][placed_last][placed_first];

}

int main() {
    
    int N, M;
    cin >> N;
    
    string pref;
    cin >> pref;
    
    vector<array<array<int, 2>, 2>> mem(N);
    for (int i = 0; i < N; i++) {
        mem[i][0][0] = -1;
        mem[i][0][1] = -1;
        mem[i][1][0] = -1;
        mem[i][1][1] = -1;
    }

    int res = max(max_satisfied(pref, 0, true, true, mem), max_satisfied(pref, 0, false, false, mem));
    cout << res << endl;
    
}
