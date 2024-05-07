
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    int A, N;
    std::cin >> A >> N;
    
    std::vector<int> lengths(N);
    for (int i = 0; i < N; i++)
        std::cin >> lengths[i];
    
    std::sort(lengths.begin(), lengths.end());
    
    int p1 = 0;
    int p2 = N-1;
    
    int count = 0;
    
    while (p1 < p2) {
        
        if (lengths[p1] * lengths[p2] >= A) {
            p1++;
            p2--;
            count++;
        } else {
            p1++;
        }
        
    }
    
    std::cout << count << std::endl;
    
}
