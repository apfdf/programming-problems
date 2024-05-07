
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    // till att börja med väljer vi den bästa intervallen så att A är med i den konstruerade
    // intervallen. Sedan väljer man den bästa intervallen så att C är eller är större en
    // det minsta talet i den valda intervallen. Om ett steg inte är möjligt vid någon punkt
    // borde det innebära att det är omöjligt att konstruera en täckande intervall.
    
    for (int _ = 0; _ < 30; _++) {
        
        float A, B;
        std::cin >> A >> B;
        
        int n;
        std::cin >> n;
        
        std::vector<float[2]> intervals(n);
        for (int i = 0; i < n; i++)
            std::cin >> intervals[i][0] >> intervals[i][1];
        
        std::vector<int> chosen_indices = {};

        if (A == B) {
            bool possible = false;
            int index;
            for (int i = 0; i < n; i++) {
                if (intervals[i][0] <= A && intervals[i][1] >= A) {
                    possible = true;
                    index = i;
                    break;
                }
            }
            if (possible) {
                std::cout << 1 << std::endl;
                std::cout << index << std::endl;
            } else {
                std::cout << "impossible" << std::endl;
            }
            continue;
        }
        
        bool possible = true;

        float hi = A;
        while (hi < B) {
            
            float best_hi = hi;
            float best_i;
            for (int i = 0; i < n; i++) {
                
                float a = intervals[i][0];
                float b = intervals[i][1];
                
                if (a <= hi && b > best_hi) {
                    best_hi = b;
                    best_i = i;
                }
                
            }
            
            if (best_hi != hi) {
                chosen_indices.push_back(best_i);
                hi = best_hi;
            } else {
                possible = false;
                break;
            }
            
        }

        if (possible) {
            std::cout << chosen_indices.size()<< std::endl;
            for (int i = 0; i < chosen_indices.size(); i++) {
                std::cout << chosen_indices[i] << " ";
            }
        } else {
            std::cout << "impossible";
        }
        std::cout << std::endl;
        
    }
    
}
