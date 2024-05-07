
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    // start with the complete sequence, then for each pair that doesn't match,
    // remove the larger one.
    
    int n;
    while (std::cin >> n) {
        
        std::vector<int> sequence(n);
        for (int i = 0; i < n; i++) 
            std::cin >> sequence[i];
        std::vector<int> indices(n);
        for (int i = 0; i < n; i++)
            indices[i] = i;
        
        int p = 0;
        while (p < sequence.size()-1) {
            if (sequence[p] >= sequence[p+1]) {
                sequence.erase(sequence.begin()+p);
                indices.erase(indices.begin()+p);
                if (p)
                    p--;
                continue;
            }
            p++;
        }
        
        std::cout << sequence.size() << std::endl;
        for (int i = 0; i < sequence.size(); i++)
            std::cout << indices[i] << " ";
        std::cout << std::endl;
        
    }
    
}
