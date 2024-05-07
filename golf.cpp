
#include <iostream>
#include <vector>
#include <array>
#include <math.h>
#include <algorithm>

int main() {

    int N;
    std::cin >> N;

    std::vector<int> x_positions(N);
    std::vector<int> y_positions(N);
    std::vector<int> z_positions(N);
    for (int i = 0; i < N; i++)
        std::cin >> x_positions[i] >> y_positions[i] >> z_positions[i];
    
    std::vector<int> order(N);
    for (int i = 0; i < N; i++)
        order[i] = i;
    
    std::sort(order.begin(), order.end(), [x_positions](int i, int j) {return x_positions[i] < x_positions[j];});
    
    int s = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            
            int ri = order[i];
            int rj = order[j];

            int x_dif = x_positions[ri] - x_positions[rj];
            int y_dif = y_positions[ri] - y_positions[rj];
            int z_dif = z_positions[ri] - z_positions[rj];

            if (x_dif > 250)
                break;

            int squared_dist = x_dif*x_dif + y_dif*y_dif + z_dif*z_dif;

            if (squared_dist <= 62500)
                s++;

        }
    }

    std::cout << s << std::endl;

}
