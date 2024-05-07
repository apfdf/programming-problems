
#include <iostream>
#include <vector>
#include <math.h>

int main() {
    
    int X;
    std::cin >> X;
    
    int original_X = X;
    
    int prime_factors = 0;

    int prod = 1;

    for (int i = 2; i < sqrt(X)+1; i++) {

        while (X % i == 0) {
            prod *= i;
            prime_factors++;
            X /= i;
        }

    }

    if (prod != original_X)
        prime_factors++;
    
    std::cout << prime_factors << std::endl;
    
}
