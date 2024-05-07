
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    
    int n, s, m;
    std::cin >> n >> s >> m;
    
    std::vector<int> squares(n);
    for (int i = 0; i < n; i++)
        std::cin >> squares[i];
    
    std::vector<bool> been_to(n);
    for (int i = 0; i < n; i++)
        been_to[i] = false;
    
    int i = 0;
    int p = s-1;
    while (true) {

        if (p < 0) {
            std::cout << "left" << std::endl;
            std::cout << i << std::endl;
            return 0;
        }
        else if (p >= n) {
            std::cout << "right" << std::endl;
            std::cout << i << std::endl;
            return 0;
        }
        if (squares[p] == m) {
            std::cout << "magic" << std::endl;
            std::cout << i << std::endl;
            return 0;
        }
        else if (been_to[p]) {
            std::cout << "cycle" << std::endl;
            std::cout << i << std::endl;
            return 0;
        }

        been_to[p] = true;
        p += squares[p];
        i++;
        
    }
    
}
