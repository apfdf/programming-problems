
#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vector<int> ocurrences = {};

    for (int i = 0; i < N; i++) {
        bool same = false;
        if (i != 0) {
            if (A[i] == A[i-1]) {
                same = true;
            }
        }
        if (same) {
            ocurrences[ocurrences.size()-1]++;
        } else {
            ocurrences.push_back(1);
        }
    }

    sort(ocurrences.begin(), ocurrences.end());
    reverse(ocurrences.begin(), ocurrences.end());

    int c = 0;
    while (c < K) {
        int m = ocurrences[0];
        for (int i = 0; i < ocurrences.size(); i++) {
            if (ocurrences[i] == m) {
                ocurrences[i]--;
                c++;
                if (c == K) {
                    break;
                }
            } else {
                break;
            }
        }
    }

    int m = ocurrences[0];
    for (int i = 0; i < ocurrences.size(); i++) {
        m = max(m, ocurrences[i]);
    }

    cout << m << endl;

    /*

    vector<int> elements = {};
    unordered_map<int, int> ocurrences;

    for (int i = 0; i < N; i++) {
        if (ocurrences.find(A[i]) == ocurrences.end()) {
            elements.push_back(A[i]);
            ocurrences[A[i]] = 1;
        } else {
            ocurrences[A[i]]++;
        }
    }

    sort(elements.begin(), elements.end(), [&ocurrences] (int a, int b) {return ocurrences[a] > ocurrences[b];});

    int c = 0;
    while (c < K) {

        int m = elements[0];
        
        for (int i = 0; i < elements.size(); i++) {

            if (ocurrences[elements[i]] < m) {
                break;
            }

            if (ocurrences[elements[i]] > 0) {
                c++;
                ocurrences[elements[i]]--;
            }

        }

    }

    cout << ocurrences[elements[0]] << endl;

    */

}
