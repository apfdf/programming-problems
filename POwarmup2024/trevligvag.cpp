
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

double get_mean(std::vector<std::array<int, 3>> edges, int current, int end, int edges_chosen, int trev) {

	// maybe binary search for first node in connection?

	if (current == end)
		return (double)trev/edges_chosen;

	// binary search edges for the first edge with current as start
	int lo = 0;
	int hi = edges.size()-1;
	while (lo+1 < hi) {
		int mid = (lo + hi) / 2;
		if (edges[mid][0] < current) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	
	std::vector<double> possible_means = {};
	for (int i = lo; i < edges.size(); i++) {
		if (edges[i][0] != current)
			break;
		double mean = get_mean(edges, edges[i][1], end, edges_chosen + 1, trev + edges[i][2]);
		if (mean != -1.0)
			possible_means.push_back(mean);
	}
	if (possible_means.size() == 0)
		return -1.0;

	/*
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i][0] == current) {
			double mean = get_mean(edges, edges[i][1], end, edges_chosen + 1, trev + edges[i][2]);
            if (mean != -1)
                possible_means.push_back(mean);
        }
    }
    if (possible_means.size() == 0)
        return -1;
	*/

	double max = possible_means[0];
	for (int i = 0; i < possible_means.size(); i++) {
		if (possible_means[i] > max)
			max = possible_means[i];
	}

	return max;    

}

int main() {

	int n, m;
	std::cin >> n >> m;

	std::vector<std::array<int, 3>> edges(m);
	for (int i = 0; i < m; i++)
		std::cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

	std::sort(edges.begin(), edges.end(), [](std::array<int, 3> a, std::array<int, 3> b) {a[0] > b[0];});

	double max_mean = get_mean(edges, 1, n, 0, 0);

	std::cout << max_mean << std::endl;

}
