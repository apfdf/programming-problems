
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

float dp(std::vector<std::array<int, 3>> edges, int current, int end, int trev, int edges_chosen) {

    if (current == end)
        return (float)trev / (float)edges_chosen;
    
    // binary search for the first edge with current as start
    int lo = 0;
    int hi = edges.size() - 1;
    while (lo+1 < hi) {
        int mid = (lo + hi) / 2;
        if (edges[mid][0] > current-1)
            hi = mid;
        else
            lo = mid;
    }
    if (edges[hi][0] != current)
        return -1;
    
    float highest_mean = 0;
    for (int i = hi; i < edges.size(); i++) {
        if (edges[i][0] != current)
            break;
        float mean = dp(edges, edges[i][1], end, trev + edges[i][2], edges_chosen+1);
        if (mean != -1) {
            if (mean > highest_mean)
                highest_mean = mean;
        }
    }

    std::cout << highest_mean << std::endl;

    if (highest_mean == 0)
        return -1;
    else
        return highest_mean;

}

int main() {

    int n, m;
    std::cin >> n >> m;

    std::vector<std::array<int, 3>> edges(m);
    for (int i = 0; i < m; i++)
        std::cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    
    std::sort(edges.begin(), edges.end(), [](std::array<int, 3> a, std::array<int, 3> b) {return a[0] > b[0];});

    float mean = dp(edges, 1, n, 0, 0);

    std::cout << mean << std::endl;

}
