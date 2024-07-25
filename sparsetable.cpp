
#include <bits/stdc++.h>
using namespace std;

int f(int a, int b) {
    return min(a, b);
}

int main() {

    vector<int> a = {1, 2, 4, 2, 5};

    int N = a.size();
    int K = ceil(log2(N));
    vector<vector<int>> sparse_table(K, vector<int>(N));

    copy(a.begin(), a.end(), sparse_table[0].begin());

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + (1 << i) <= N /* ! */; j++) {
            sparse_table[i][j] = f(sparse_table[i-1][j], sparse_table[i-1][j + (1 << (i-1))]); // huh
        }
    }



}
