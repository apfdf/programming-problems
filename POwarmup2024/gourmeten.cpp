
#include <iostream>
#include <vector>
#include <math.h>

int prod(int n, int m) {
	int p = 1;
	for (int i = n; i < m+1; i++)
		p *= i;
	return p;
}

int dp(std::vector<int> meals, int t, int i, int on_same, int picked, int ways, int ways0) {

	if (t == 0)
		return ways * prod(picked, picked + on_same) / prod(1, on_same);
	if (t < 0 || i == meals.size()) {
		return 0;
	} else {
		int pick = dp(meals, t - meals[i], i, on_same+1, picked+1, ways0 * prod((picked+1) - (on_same), picked+1) / prod(1, on_same+1), ways0);
		int skip = dp(meals, t, i+1, 0, picked, ways, ways);
		return pick + skip;
	}

}

int main() {

	int M, N;
	std::cin >> M >> N;

	std::vector<int> meals(N);
	for (int i = 0; i < N; i++)
		std::cin >> meals[i];

	int ways = dp(meals, M, 0, 0, 0, 1, 1);
	std::cout << ways << std::endl;

}
