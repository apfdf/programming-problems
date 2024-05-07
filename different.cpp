
#include <iostream>

int main() {
    
    int a, b;
    while (std::cin >> a >> b) {
        
        int lo = (a >= b) ? b : a;
        int hi = (lo == a) ? b : a;
        
        std::cout << hi - lo << std::endl;
        
    }
    
}
