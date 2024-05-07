
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    unordered_map<string, int> ntv;
    unordered_map<string, int> ntg;
    unordered_map<int, string> vtn;

    for (int i = -10000; i < 10000+1; i++) {
        vtn[i] = "";
    }
    ntg[""] = -1;
    
    vector<vector<string>> rows;
    string command;
    for (int i = 0; i < 2000; i++) {
        if (cin >> command) {
            if (command == "0") {
                break;
            }
            vector<string> row = {command};
            if (command == "def") {
                string name, val;
                cin >> name >> val;
                row.push_back(name);
                row.push_back(val);
                ntg[name] = -1;
            } else if (command == "calc") {
                int j = 0;
                while (true) {
                    string token;
                    cin >> token;
                    row.push_back(token);
                    if (token == "=") {
                        break;
                    }
                    if (j % 2 == 0) {
                        ntg[token] = -1;
                    }
                    j++;
                }
            }
            rows.push_back(row);
        } else {
            break;
        }
    }

    int gen = 0;

    for (int i = 0; i < rows.size(); i++) {

        string action = rows[i][0];
        if (action == "def") {

            string name;
            int val;
            name = rows[i][1];
            val = stoi(rows[i][2]);

            ntv[name] = val;
            vtn[val] = name;
            ntg[name] = gen;

        } else if (action == "calc") {

            vector<string> names = {};
            vector<int> signs = {};

            for (int j = 0; j < rows[i].size()-1; j++) {
                if (j % 2 == 0) {
                    names.push_back(rows[i][j+1]);
                } else {
                    signs.push_back((rows[i][j+1] == "+") ? 1 : -1);
                }
            }

            bool known = true;
            int sign = 1;
            int s = 0;
            for (int j = 0; j < names.size(); j++) {
                if (ntg[names[j]] != gen) {
                    known = false;
                    break;
                }
                int val = ntv[names[j]];
                s += sign * val;
                if (j < signs.size()) {
                    sign = signs[j];
                }
            }

            string res;

            if (!known || abs(s) > 10000) {
                res = "unknown";
            } else {
                string name = vtn[s];
                if (ntg[name] == gen) {
                    res = name;
                } else {
                    res = "unknown";
                }
            }

            for (int j = 1; j < rows[i].size(); j++) {
                cout << rows[i][j] << " ";
            }
            cout << res << endl;

        } else if (action == "clear") {

            gen++;

        }

    }

}
