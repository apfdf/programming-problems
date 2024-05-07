
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> vax_days(N);
    for (int i = 0; i < N; i++)
        std::cin >> vax_days[i];
    
    std::vector<int> prefix_sum(N);
    int s = 0;
    for (int i = 0; i < N; i++) {
        s += vax_days[i];
        prefix_sum[i] = s;
    }
    
    // binärsök prefix summen?????
    
    // prova naivt
    for (int i = 0; i < Q; i++) {
        
        int p;
        std::cin >> p;
        
        bool knowable = false;
        
        int lo = 0;
        int hi = N-1;
        
        while (lo+1 < hi) {
            
            int mid = lo + int((hi - lo) / 2);
            if (prefix_sum[mid] > p)
                hi = mid;
            else
                lo = mid;
            
        }

        if (prefix_sum[lo] > p)
            std::cout << lo+1 << std::endl;
        else if (prefix_sum[hi] > p)
            std::cout << hi+1 << std::endl;
        else
            std::cout << -1 << std::endl;
        
        /*
        for (int j = 0; j < N; j++) {
            if (prefix_sum[j] > p) {
                knowable = true;
                std::cout << j+1 << std::endl;
                break;
            }
        }
        if (!knowable)
            std::cout << -1 << std::endl;
        */
        
    }
    
}
