
#include <iostream>
#include <string>
#include <vector>

int main() {
    
    int N;
    std::cin >> N;
    
    std::string row_s;
    std::cin >> row_s;
    
    std::vector<bool> row(N);
    for (int i = 0; i < N; i++)
        row[i] = (row_s[i] == '.');
    
    int lo;
    int hi;
    for (int i = 0; i < N; i++) {
        if (row[i]) {
            lo = i;
            break;
        }
    }
    for (int i = lo+1; i < N; i++) {
        if (row[i]) {
            hi = i;
            break;
        }
    }
    
    int lowest_dist = hi - lo - 1;
    
    while (true) {
        
        lo = hi;

        bool should_break = false;
        do {
            hi++;
            if (hi >= N) {
                should_break = true;
                break;
            }
        } while (!row[hi]);
        
        if (should_break)
            break;

        int d = hi - lo - 1;
        if (d < lowest_dist)
            lowest_dist = d;
        
    }
    
    std::cout << lowest_dist << std::endl;
    
}
