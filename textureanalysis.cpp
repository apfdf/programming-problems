
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    int test_case = 1;
    string row;
    while (true) {
        
        cin >> row;
        if (row == "END") {
            break;
        }
        
        bool even = true;
        
        int prev_spacing = -1;
        int consecutive_whites = 0;
        for (int i = 1; i < row.size(); i++) {
            if (row[i] == '.') {
                consecutive_whites++;
            } else if (row[i] == '*') {
                if (prev_spacing == -1 || consecutive_whites == prev_spacing) {
                    prev_spacing = consecutive_whites;
                    consecutive_whites = 0;
                } else {
                    even = false;
                    break;
                }
            }
        }
        
        if (even) {
            cout << test_case << " EVEN" << endl;
        } else {
            cout << test_case << " NOT EVEN" << endl;
        }
        
        test_case++;
        
    }
    
}
