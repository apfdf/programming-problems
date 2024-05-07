
#include <bits/stdc++.h>

using namespace std;

#define TWO_SIZE 32
#define THREE_SIZE 21
#define FIVE_SIZE 14
#define SEVEN_SIZE 12

typedef long long int ll;

/*
bool first_wins(ll n, ll p, bool first, vector<vector<bool>>& mem, vector<vector<bool>>& vis, int twos, int nines) {
    
    if (p >= n) {
        return !first;
    }
    
    if (vis[twos][nines]) {
        return mem[twos][nines];
    }

    vis[twos][nines] = true;
    
    if (first) {
        if (first_wins(n, p*2, false, mem, vis, twos+1, nines) || first_wins(n, p*9, false, mem, vis, twos, nines+1)) {
            mem[twos][nines] = true;
            return true;
        } else {
            mem[twos][nines] = false;
            return false;
        }
    } else {
        if (first_wins(n, p*2, true, mem, vis, twos+1, nines) && first_wins(n, p*9, true, mem, vis, twos, nines+1)) {
            mem[twos][nines] = true;
            return true;
        } else {
            mem[twos][nines] = false;
            return false;
        }
    }

}
*/

bool first_wins(ll n, ll p, bool first, bool mem[TWO_SIZE][THREE_SIZE][FIVE_SIZE][SEVEN_SIZE], bool vis[TWO_SIZE][THREE_SIZE][FIVE_SIZE][SEVEN_SIZE], int twos, int threes, int fives, int sevens) {
    
    if (p >= n) {
        return !first;
    }
    
    if (vis[twos][threes][fives][sevens]) {
        return mem[twos][threes][fives][sevens];
    }

    vis[twos][threes][fives][sevens] = true;

    vector<array<int, 4>> prime_changes = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {2, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 1},
        {3, 0, 0, 0},
        {0, 2, 0, 0}
    };

    if (first) {
        for (array<int, 4> prime_change : prime_changes) {
            ll next_p = p * pow(2, prime_change[0]) * pow(3, prime_change[1]) * pow(5, prime_change[2]) * pow(7, prime_change[3]);
            if (first_wins(n, next_p, false, mem, vis, twos + prime_change[0], threes + prime_change[1], fives + prime_change[2], sevens + prime_change[3])) {
                mem[twos][threes][fives][sevens] = true;
                return true;
            }
        }
        mem[twos][threes][fives][sevens] = false;
        return false;
    } else {
        for (array<int, 4> prime_change : prime_changes) {
            ll next_p = p * pow(2, prime_change[0]) * pow(3, prime_change[1]) * pow(5, prime_change[2]) * pow(7, prime_change[3]);
            if (!first_wins(n, next_p, true, mem, vis, twos + prime_change[0], threes + prime_change[1], fives + prime_change[2], sevens + prime_change[3])) {
                mem[twos][threes][fives][sevens] = false;
                return false;
            }
        }
        mem[twos][threes][fives][sevens] = true;
        return true;
    }

}

int main() {

    // mem of log2(10^9) * log3(10^9) * log5(10^9) * log7(10^9) = ~10^4 (possible)
    
    ll n;
    while (cin >> n) {

        bool mem[TWO_SIZE][THREE_SIZE][FIVE_SIZE][SEVEN_SIZE];
        bool vis[TWO_SIZE][THREE_SIZE][FIVE_SIZE][SEVEN_SIZE];

        if (first_wins(n, 1, true, mem, vis, 0, 0, 0, 0)) {
            cout << "Stan wins." << endl;
        } else {
            cout << "Ollie wins." << endl;
        }
        
        // try the combinations of 2:s and 9:s that can be chosen before the product exceeds n
        
        // DP???
        
    }
    
}
