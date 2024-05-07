
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N;
    cin >> N;

    vector<pair<int, int>> coords1(N);
    vector<pair<int, int>> coords2(N);
    for (int i = 0; i < N; i++) {
        cin >> coords1[i].first >> coords1[i].second;
    }
    for (int i = 0; i < N; i++) {
        cin >> coords2[i].first >> coords2[i].second;
    }
    
    // find the most common combination of u and v, then simulate for them
    map<pair<int, int>, int> freq;
    int max_freq = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int u = coords2[j].first - coords1[i].first;
            int v = coords2[j].second - coords1[i].second;
            if (freq.find({u, v}) != freq.end()) {
                freq[{u, v}]++;
            } else {
                freq[{u, v}] = 1;
            }
            if (freq[{u, v}] > max_freq) {
                max_freq = freq[{u, v}];
            }
        }
    }

    cout << N - max_freq << endl;
    
}
