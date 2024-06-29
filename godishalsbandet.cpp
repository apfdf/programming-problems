
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string band;
    cin >> band;
    
    int len = band.size();
    band += band;
    
    vector<int> prefix(band.size());
    int s = 0;
    for (int i = 0; i < band.size(); i++) {
        prefix[i] = s;
        if (band[i] == 'B') {
            s++;
        }
    }
    
    int m = 0;
    for (int i = 0; i < len; i++) {
        int blues = prefix[i+len/2] - prefix[i];
        m = max(m, blues);
    }
    
    cout << m << endl;
    
}
