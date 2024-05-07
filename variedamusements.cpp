
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp(int n, int a, int b, int c, int chosen) {
    if (n == 0) {
        return 1;
    }
    int s = 0;
    if (chosen != 0) {
        s += (a * dp(n-1, a, b, c, 0)) % (1000000000 + 7);
    }
    if (chosen != 1) {
        s += b * dp(n-1, a, b, c, 1) % (1000000000 + 7);
    }
    if (chosen != 2) {
        s += c * dp(n-1, a, b, c, 2) % (1000000000 + 7);
    }
    return s;
}

int main() {
    
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    cout << dp(n, a, b, c, -1) << endl;
    
}
