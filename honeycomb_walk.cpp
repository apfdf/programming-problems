
#include <iostream>

int get_origin_paths(int n, int i, int j) {

    if (n == 0) {
        return (i == 0 && j == 0) ? 1 : 0;
    }

    // this can be improved
    if (abs(i) > n || abs(j) > n) {
        return 0;
    } else if (((i >= 0 && j < 0) || (i <= 0 && j > 0)) && n < abs(i) + abs(j)) {
        return 0;
    }

    return 
    get_origin_paths(n-1, i+1, j) + 
    get_origin_paths(n-1, i-1, j) +
    get_origin_paths(n-1, i, j+1) +
    get_origin_paths(n-1, i, j-1) +
    get_origin_paths(n-1, i+1, j+1) +
    get_origin_paths(n-1, i-1, j-1);

}

int main() {

    int cases;
    std::cin >> cases;

    for (int i = 0; i < cases; i++) {

        int steps;
        std::cin >> steps;

        std::cout << get_origin_paths(steps, 0, 0) << std::endl;

    }

}
