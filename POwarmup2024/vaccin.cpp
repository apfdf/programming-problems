
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> days(N);
    for (int i = 0; i < N; i++)
        std::cin >> days[i];
        
    std::vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        std::cin >> queries[i];
    
    std::vector<int> prefix(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += days[i];
        prefix[i] = sum;
    }

    for (int i = 0; i < Q; i++) {
        
        int p = queries[i];
        if (p > prefix[N-1]-1) {
            
            std::cout << -1 << std::endl;

        } else {
            
            int lo = 0;
            int hi = N-1;

            while (lo+1 < hi) {

                int mid = std::floor((lo+hi)/2);
                if (p < prefix[mid]) {
                    hi = mid;
                } else {
                    lo = mid;
                }

            }

            if (p >= prefix[lo] - days[lo] && p < prefix[lo]) {
                std::cout << lo+1 << std::endl;
            } else {
                std::cout << hi+1 << std::endl;
            }

            /*
            for (int i = 0; i < N; i++) {
                if (p >= prefix[i] - days[i] && p < prefix[i]) {
                    std::cout << i+1 << std::endl;
                    break;
                }
            }
            */

        }
        
    }
    
}
