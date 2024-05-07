

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    
    while (true) {
        
        
        int n1, n2, n3, n4;
        cin >> n1 >> n2 >> n3 >> n4;
        
        if (n1 == 0 && n2 == 0 && n3 == 0 && n4 == 0) {
            break;
        }

        int num_dif = 0;
        num_dif += 80;
        num_dif += (n2 >= n1) ? n2 - n1 : n2 + 40 - n1;
        num_dif += 40;
        num_dif += (n2 >= n3) ? n2 - n3 : n2 + 40 - n3;
        num_dif += (n4 >= n3) ? n4 - n3 : n4 + 40 - n3;
        
        int degrees_turned = num_dif * (360 / 40);
        
        cout << degrees_turned << endl;
    
    }
    
}

