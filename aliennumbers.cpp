
#include <iostream>
#include <string>

using namespace std;

int pow(int base, int exponent) {
    int prod = 1;
    for (int i = 0; i < exponent; i++) {
        prod *= base;
    }
    return prod;
}

int main() {
    
    int T;
    cin >> T;
    
    string alien_num, source, target;
    cin >> alien_num >> source >> target;

    int source_base = source.size();
    int target_base = target.size();

    // convert num to int
    int num = 0;
    for (int i = 0; i < alien_num.size(); i++) {

        for (int j = 0; j < source_base; j++) {
            if (alien_num[alien_num.size()-1-i] == source[i]) {
                num += pow(j, i);
            }
        }

    }

    

}
