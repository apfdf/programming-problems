
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    string s;
    cin >> s;
    
    int len = s.size();
    
    vector<bool> checked(len);
    for (int i = 0; i < len; i++) {
        checked[i] = false;
    }
    
    int lowest_add = -1;
    
    for (int i = 0; i < len; i++) {
        
        if (checked[i]) {
            continue;
        }
        
        int start_index = 0;
        for (int j = 0; j < alphabet.size(); j++) {
            if (s[i] == alphabet[j]) {
                start_index = j;
            }
        }
        int end_index = start_index+1;
        for (int j = i; j < len; j++) {
            if (end_index >= alphabet.size()) {
                break;
            }
            if (s[j] == alphabet[end_index]) {
                checked[j] = true;
                end_index++;
            }
        }
        
        int to_add = len - (end_index - start_index);
        if (lowest_add == -1 || to_add < lowest_add) {
            lowest_add = to_add;
        }
        
    }
    
    cout << lowest_add << endl;
    
}
