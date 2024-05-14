
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp(string seq, int i, vector<ll>& mem) {
    
    if (i > seq.size()-1) {
        return 1;
    }

    if (i == seq.size()-1) {
        if (seq[i] != '0') {
            return 1;
        } else {
            return 0;
        }
    }
    
    if (mem[i] != -1) {
        return mem[i];
    }
    
    if (seq[i] == '0') {
        return 0;
    }

    ll s = 0;

    s += dp(seq, i+1, mem);
    if (seq[i] == '1' || seq[i] == '2') {
        s += dp(seq, i+2, mem);
    }

    mem[i] = s;
    return mem[i];
    
}

int main() {
    
    string seq;
    cin >> seq;

    vector<ll> mem(seq.size(), -1);
    
    cout << dp(seq, 0, mem) << endl;
    
}
