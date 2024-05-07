
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> Dv(N);
    for (int i = 0; i < N; i++) {
        cin >> Dv[i];
    }
    random_shuffle(Dv.begin(), Dv.end());

    multiset<int> D;
    for (int i = 0; i < N; i++) {
        D.insert(Dv[i]);
    }
    
    for (int i = 0; i < Q; i++) {
        
        int T, d;
        cin >> T >> d;

        if (T == 1) {

            auto it = upper_bound(D.begin(), D.end(), d);
            if (it == D.end()) {
                cout << -1 << endl;
                continue;
            }

            cout << *it << endl;
            D.erase(it);

        } else if (T == 2) {

            auto it = upper_bound(D.begin(), D.end(), d);
            if (it == D.begin()) {
                cout << -1 << endl;
                continue;
            }

            it--;
            cout << *it << endl;
            D.erase(it);

        }
        
    }
    
}
