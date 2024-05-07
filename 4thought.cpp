
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    
    int m;
    std::cin >> m;
    
    for (int _ = 0; _ < m; _++) {
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    
                    std::vector<int> nums(4, 4);
                    
                    if (i == 3) {
                        nums.erase(&nums[0]);
                        nums[0] = 1;
                    }
                    if (j == 3) {
                        
                    }
                    
                }
            }
        }
    
    }
    
}
