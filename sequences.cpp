
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    string s;
    cin >> s;

    ll base_sum = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            base_sum += i;
            base_sum = base_sum % 1000000007;
        }
    }

    vector<int> unknowns = {};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?')
    }

}
