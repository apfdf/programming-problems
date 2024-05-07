
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    
    
    int N;
    std::cin >> N;

    std::vector<int> diffs(N);
    for (int i = 0; i < N; i++) {
        int F, S;
        std::cin >> F >> S;
        diffs[i] = F - S;
    }

    std::vector<int> unique_diffs = {};
    for (int i = 0; i < N; i++) {
        int dif = abs(diffs[i]);
        if (std::find(unique_diffs.begin(), unique_diffs.end(), dif) == unique_diffs.end())
            unique_diffs.push_back(dif);
    }

    std::sort(unique_diffs.begin(), unique_diffs.end());
    std::sort(diffs.begin(), diffs.end(), [](int n, int m) {return (abs(n) < abs(m));});

    int F_wins = std::count_if(diffs.begin(), diffs.end(), [](int d) {return (d > 0);});
    int S_wins = std::count_if(diffs.begin(), diffs.end(), [](int d) {return (d < 0);});

    int match_dif = F_wins - S_wins;

    int highest_match_dif = match_dif;
    int best_bound = 0;

    int piv = 0;

    for (int i = 0; i < unique_diffs.size(); i++) {

        for (piv; piv < N; piv++) {

            if (abs(diffs[piv]) != unique_diffs[i])
                break;
            
            if (diffs[piv] > 0)
                match_dif -= 1;
            else
                match_dif += 1;

        }

        if (match_dif > highest_match_dif) {
            highest_match_dif = match_dif;
            best_bound = unique_diffs[i];
        }

    }

    std::cout << best_bound << std::endl;

}
