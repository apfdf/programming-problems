
#include <iostream>
#include <vector>

long long unsigned int dp(std::vector<int> meals, int i, int t, int on_same, int picked, long long unsigned int ways) {
    
    if (t == 0)
        return ways;
    if (t < 0 || i == meals.size())
        return 0;
    
    long long unsigned int pick = dp(meals, i, t - meals[i], on_same+1, picked+1, (ways * (picked+1)) / (on_same+1));
    long long unsigned int skip = dp(meals, i+1, t, 0, picked, ways);
    return pick + skip;

}

int main() {

    int M, N;
    std::cin >> M >> N;

    std::vector<int> meals(N);
    for (int i = 0; i < N; i++)
        std::cin >> meals[i];

    long long unsigned int ways = dp(meals, 0, M, 0, 0, 1);
    std::cout << ways << std::endl;

}
