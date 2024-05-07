
#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int>& A, int lo, int hi) {

    if (hi - lo == 2) {
        
        if (A[hi-1] < A[lo]) {
            int temp = A[lo];
            A[lo] = A[hi-1];
            A[hi-1] = temp;
        }

    } else if (hi - lo > 2) {

        int mid = (lo + hi) / 2;
        merge_sort(A, lo, mid);
        merge_sort(A, mid, hi);

        vector<int> new_seq(hi - lo);
        int lp = lo;
        int rp = mid;
        for (int i = 0; i < hi - lo; i++) {

            if (lp == mid) {
                new_seq[i] = A[rp];
                rp++;
                continue;
            }
            if (rp == hi) {
                new_seq[i] = A[lp];
                lp++;
                continue;
            }

            if (A[lp] < A[rp]) {
                new_seq[i] = A[lp];
                lp++;
            } else {
                new_seq[i] = A[rp];
                rp++;
            }

        }

        for (int i = 0; i < hi - lo; i++) {
            A[lo+i] = new_seq[i];
        }

    }

}

int main() {

    vector<int> A = {5, 4, 3, 2, 1};

    merge_sort(A, 0, A.size());
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i < A.size()-1) {
            cout << " ";
        }
    }
    cout << endl;

}
