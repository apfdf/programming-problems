
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N, K;
    cin >> N >> K;
    
    vector<string> cell_types(N);
    for (int i = 0; i < N; i++) {
        cin >> cell_types[i];
    }
    
    sort(cell_types.begin(), cell_types.end());

    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        
        string cell_type;
        cin >> cell_type;
        
        int lo = 0;
        int hi = N-1;
        
        while (lo != hi) {
            
            int mid = (lo + hi) / 2;
            
            if (cell_types[mid] >= cell_type) {
                hi = mid;
            } else {
                lo = mid+1;
            }
            
        }

        cout << "# " << lo << endl;
        
        if (cell_type == cell_types[lo]) {

            bool singular = true;
            if (lo < N-1) {
                if (cell_types[lo+1] == cell_type) {
                    singular = false;
                }
            }
            
            if (singular) {
                cout << lo+1 << endl;
            } else {
                cout << "vet ej" << endl;
            }

        } else {

            cout << "finns ej" << endl;

        }
        
    }
    
}
