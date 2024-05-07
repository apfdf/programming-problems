
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int n;
    while (cin >> n) {
        
        int sum = 0;
        
        int upper_bound = floor(sqrt(n));
        for (int d = 1; d < upper_bound+1; d++) {
            if (n % d == 0) {
                int quotient = n / d;
                sum += d;
                if (quotient != d && quotient < n) {
                    sum += quotient;
                }
            }
        }
        
        cout << n << " ";
        if (sum == n) {
            cout << "perfect";
        } else if (abs (n - sum) <= 2) {
            cout << "almost perfect";
        } else {
            cout << "not perfect";
        }
        cout << endl;
        
    }
    
}
