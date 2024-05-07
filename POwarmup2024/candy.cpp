
#include <iostream>
#include <vector>
#include <map>
#include <array>

int main() {

    int N;
    std::cin >> N;

    std::map<int, int> candies;
    for (int i = -10; i < 10+1; i++) {
        if (i != 0)
            candies[i] = 0;
    }

    std::vector<std::vector<std::array<int, 2>>> bags(N);
    for (int i = 0; i < N; i++) {
        
        int n;
        std::cin >> n;
        
        for (int j = 0; j < n; j++) {
            std::cin >> bags[i][j][0] >> bags[i][j][1];
            candies[bags[i][j][0]] += bags[i][j][1];
        }

    }

    

}
