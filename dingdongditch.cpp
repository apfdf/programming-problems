
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<long long int> anger_levels(N);
    for (int i = 0; i < N; i++)
        std::cin >> anger_levels[i];
    std::sort(anger_levels.begin(), anger_levels.end());
    
    std::vector<long long int> prefix_sum(N);
    long long int s = 0;
    for (int i = 0; i < N; i++) {
        s += anger_levels[i];
        prefix_sum[i] = s;
    }
    
    for (int i = 0; i < Q; i++) {
        long long int B;
        std::cin >> B;
        std::cout << prefix_sum[B-1] << std::endl;
    }
    
}
