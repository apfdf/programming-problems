
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

int main() {

    int N, K, R;
    std::cin >> N >> K >> R;

    std::vector<int> DNA(N);
    for (int i = 0; i < N; i++)
        std::cin >> DNA[i];

    std::vector<int> bases(R);
    std::vector<int> req_vec(R);
    for (int i = 0; i < R; i++)
        std::cin >> bases[i] >> req_vec[i];

    std::map<int, int> requirements;
    for (int i = 0; i < R; i++)
        requirements[bases[i]] = req_vec[i];

    std::map<int, int> bases_got;
    for (int i = 0; i < R; i++)
        bases_got[bases[i]] = 0;

    int lo = 0;
    int hi = -1;
    bool valid = false;
    
    while (!valid) {
        
        hi++;

        valid = true;

        if (hi >= N) {
            std::cout << "impossible" << std::endl;
            return 0;
        }

        if (std::count(bases.begin(), bases.end(), DNA[hi]) == 0) {
            valid = false;
            continue;
        }

        bases_got[DNA[hi]]++;

        for (int i = 0; i < R; i++) {
            if (requirements[bases[i]] > bases_got[bases[i]])
                valid = false;
        }

    }

    int lowest_interval = hi+1;
    bool last = false;

    while (!last) {

        int interval_len = hi - lo + 1;
        if (interval_len < lowest_interval)
            lowest_interval = interval_len;

        lo++;
        
        if (std::count(bases.begin(), bases.end(), DNA[lo-1]) == 0)
            continue;
        
        bases_got[DNA[lo-1]]--;

        if (bases_got[DNA[lo-1]] < requirements[DNA[lo-1]]) {

            while (DNA[hi] != DNA[lo-1]) {
                
                hi++;

                if (hi >= N) {
                    last = true;
                    break;
                }

                if (std::count(bases.begin(), bases.end(), DNA[hi]) != 0)
                    bases_got[DNA[hi]]++;

            }

        }

    }

    std::cout << lowest_interval << std::endl;

}
