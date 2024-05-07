
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<string> seqs = {
        "at",
        "and",
        "one", "won",
        "to", "too", "two",
        "for", "four",
        "bea", "be", "bee",
        "sea", "see",
        "eye",
        "oh", "owe",
        "are",
        "you",
        "why"
    };

    sort(seqs.begin(), seqs.end(), [](string s1, string s2) {return s1.size() > s2.size();});

    unordered_map<string, char> shortenings;
    shortenings["at"] = '@';
    shortenings["and"] = '&';
    shortenings["one"] = '1';
    shortenings["won"] = '1';
    shortenings["to"] = '2';
    shortenings["too"] = '2';
    shortenings["two"] = '2';
    shortenings["for"] = '4';
    shortenings["four"] = '4';
    shortenings["bea"] = 'b';
    shortenings["be"] = 'b';
    shortenings["bee"] = 'b';
    shortenings["sea"] = 'c';
    shortenings["see"] = 'c';
    shortenings["eye"] = 'i';
    shortenings["oh"] = 'o';
    shortenings["owe"] = 'o';
    shortenings["are"] = 'r';
    shortenings["you"] = 'u';
    shortenings["why"] = 'y';

    

    for (int t = 0; t < n; t++) {
        
        string line;
        getline(cin, line);

        string out_line = "";
        
        int p = 0;
        while (p < line.size()) {
            bool found_fitting = false;
            for (string seq : seqs) {
                if (p + seq.size() >= line.size()) {
                    continue;
                }
                bool fits = true;
                for (int i = 0; i < seq.size(); i++) {
                    if (line[p+i] != seq[i]) {
                        fits = false;
                        break;
                    }
                }
                if (fits) {
                    found_fitting = true;
                    p += seq.size();
                    out_line += shortenings[seq];
                    break;
                }
            }
            if (!found_fitting) {
                p++;
                out_line += line[p];
            }
        }

        cout << out_line << endl;

    }
    
}
