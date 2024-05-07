
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    
    ll N, M;
    cin >> N >> M;
    
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<ll> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    if (N == M) {

        ll s = 0;
        for (int i = 0; i < N; i++) {
            s += abs(A[i] - B[i]);
        }
        
        cout << s << endl;
        
    } else {
        
        ll s = 0;
        for (int i = 0; i < N; i++) {
            s += abs(A[i] - B[i+1]);
        }
        
        ll m = s;
        
        for (int i = 1; i < M; i++) {
            
            s -= abs(A[i-1] - B[i]);
            s += abs(A[i-1] - B[i-1]);
            
            if (s < m) {
                m = s;
            }
            
        }
        
        cout << m << endl;
        
    }
    
    
}
