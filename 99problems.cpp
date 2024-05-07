
#include <iostream>

int main() {
    
    int N;
    std::cin >> N;
    
    if (N < 100) {
        std::cout << 99 << std::endl;
        return 0;
    }
    
    int n = N % 100;
    
    if (n < 49) {
        std::cout << N - n - 1 << std::endl;
    } else if (n >= 49) {
        std::cout << N + (99 - n) << std::endl;
    }
    
}
