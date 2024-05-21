
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // idé: hitta alla skärningspunkter
    
    // skapa en lista av par av x-koordinater
    
    int N;
    cin >> N;
    vector<pair<int, int>> peaks(N);
    for (int i = 0; i < N; i++) {
        cin >> peaks[i].first >> peaks[i].second;
    }
    
    vector<pair<int, int>> intervals(N);
    for (int i = 0; i < N; i++) {
        intervals[i].first = peaks[i].first - peaks[i].second;
        intervals[i].second = peaks[i].first + peaks[i].second;
    }
    sort(intervals.begin(), intervals.end(), [](pair<int, int> p1, pair<int, int> p2) {return p1.first < p2.first;});
    
    // om inga berg helt överlappa andra borde det kunna hanteras som att berg bara överlappar med intilliggande: O(NlogN)?

    float area = 0.0f;

    int p1 = -1;
    int p2 = 0;
    while (p2 < N) {

        area += (float)((intervals[p2].second - intervals[p2].first)*(intervals[p2].second - intervals[p2].first)) / 4;

        if (p1 != -1) {
            cout << "test" << endl;
            if (intervals[p2].first < intervals[p1].second) {
                cout << "* " << p1 << endl;
                area -= (float)((intervals[p1].second - intervals[p2].first)*(intervals[p1].second - intervals[p2].first)) / 4;
            }
        }

        p1 = p2;

        while (p2 < N) {
            if (intervals[p2].second > intervals[p1].second) {
                break;
            }
            p2++;
        }

    }

    cout << fixed << area << endl;

}
