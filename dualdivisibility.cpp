
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int a, b;
    cin >> a >> b;
    
    int divisors = 0;
    int b_multiple = b;
    while (b_multiple <= a) {
        if (a % b_multiple == 0) {
            divisors++;
        }
        b_multiple += b;
    }
    
    cout << divisors << endl;
    
}
