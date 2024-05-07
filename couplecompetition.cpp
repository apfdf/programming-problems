
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int main() {
    
    // keep track of the two closest highest blocks (TWO POINTER!!!!)
    
    int N;
    std::cin >> N;
    
    std::vector<int> blocks(N);
    for (int& block : blocks)
        std::cin >> block;
    
    std::vector<int> min_steps(N);

    // för varje steg, om det inte är möjligt att gå till den förra så måste det vara den andra
    int max = *std::max_element(blocks.begin(), blocks.end());
    
    // Idé: iterera genom varje maxpunkt och fyll i de distanserna mellan den och nästa maxpunkt. Den precis efter en maxpunkt kommer man kunna gå tillbaka till maxpunkten på ett steg.
    // man kan gå från båda hållen och så blir det epic

    // find the positions of the two first max elements
    int p1 = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0 && i < N-1) {
            if (blocks[i-1] <= blocks[i] && blocks[i+1] <= blocks[i]) {
                p1 = i;
                break;
            }            
        } else if (i > 0) {
            if (blocks[i-1] <= blocks[i]) {
                p1 = i;
                break;
            }
        } else if (i < N-1) {
            if (blocks[i+1] <= blocks[i]) {
                p1 = i;
                break;
            }
        }
    }
    int p2 = -1;
    for (int i = p1+1; i < N; i++) {
        if (i > 0 && i < N-1) {
            if (blocks[i-1] <= blocks[i] && blocks[i+1] <= blocks[i]) {
                p2 = i;
                break;
            }            
        } else if (i > 0) {
            if (blocks[i-1] <= blocks[i]) {
                p2 = i;
                break;
            }
        } else if (i < N-1) {
            if (blocks[i+1] <= blocks[i]) {
                p2 = i;
                break;
            }
        }
    }

    // fill in (0, p1)
    for (int i = 0; i < p1; i++)
        min_steps[i] = p1 - i;

    while (p2 != -1) {
        
        // filling in the interval [p1, p2]

        min_steps[p1] = 0;
        min_steps[p2] = 0;

        bool shifted = false;
        for (int i = p1+1; i < p1 + (p2 - p1) / 2 + 1; i++) {
            
            if (blocks[i] >= blocks[i-1])
                shifted = true;

            if (shifted)
                min_steps[i] = p2 - i;
            else
                min_steps[i] = i - p1;

        }
        shifted = false;
        for (int i = p2-1; i > p1 + (p2 - p1) / 2; i--) {

            if (blocks[i] >= blocks[i+1])
                shifted = true;
            
            if (shifted)
                min_steps[i] = i - p1;
            else
                min_steps[i] = p2 - i;

        }

        // choosing next pointers
        p1 = p2;
        p2 = -1;
        for (int i = p1+1; i < N; i++) {
            if (i > 0 && i < N-1) {
                if (blocks[i-1] <= blocks[i] && blocks[i+1] <= blocks[i]) {
                    p2 = i;
                    break;
                }            
            } else if (i > 0) {
                if (blocks[i-1] <= blocks[i]) {
                    p2 = i;
                    break;
                }
            } else if (i < N-1) {
                if (blocks[i+1] <= blocks[i]) {
                    p2 = i;
                    break;
                }
            }
        }

    }
    
    // fill in (p1, N)
    for (int i = p1+1; i < N; i++)
        min_steps[i] = i - p1;

    for (int min_step : min_steps)
        std::cout << min_step << " ";
    std::cout << std::endl;

}
