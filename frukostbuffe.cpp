
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {

    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    vector<ll> prefix(N);
    ll s = 0;
    for (int i = 0; i < N; i++) {
        s += nums[i];
        prefix[i] = s;
    }

    vector<int> lr_min(N);
    ll pref_min = 0;
    for (int i = 0; i < N; i++) {
        if (prefix[i] - nums[i] < prefix[pref_min] - nums[pref_min]) {
            pref_min = i;
        }
        lr_min[i] = pref_min;
    }
    vector<int> rl_max(N);
    ll pref_max = N-1;
    for (int i = 0; i < N; i++) {
        if (prefix[N-1-i] > prefix[pref_max]) {
            pref_max = N-1-i;
        }
        rl_max[N-1-i] = pref_max;
    }

    ll ans = nums[0];
    for (int i = 0; i < N; i++) {
        
        ll left = prefix[i] - prefix[lr_min[i]] + nums[lr_min[i]];
        ll right = prefix[rl_max[i]] - prefix[i] + nums[i];

        if (ans < min(left, right)) {
            ans = min(left, right);
        }

    }

    cout << ans << endl;

}
