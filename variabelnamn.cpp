
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int N;
    cin >> N;
    
    vector<int> names(N);
    for (int i = 0; i < N; i++) {
        cin >> names[i];
    }
    
    vector<bool> selected(10000 * 2 * 100000 + 1, false);
    for (int i = 0; i < N; i++) {
        int name = names[i];
        int compromise = name;
        while (selected[compromise]) {
            compromise += name;
        }
        selected[compromise] = true;
        cout << compromise << endl;
    }
    
    /*
    vector<int> selected = {};
    for (int i = 0; i < N; i++) {
        int name = names[i];
        int compromise = name;
        while (find(selected.begin(), selected.end(), compromise) != selected.end()) {
            compromise += name;
        }
        selected.push_back(compromise);
        cout << compromise << endl;
    }
    */
    
}
