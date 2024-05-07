
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

/*
void trim_tree(vector<vector<int>>& connections, vector<int> specials, int current, int prev, int& edges_left) {

    if (connections[current-1].size() > 1 || current == 1) {
        vector<int> surrounding = connections[current-1];
        for (int i = 0; i < connections[current-1].size(); i++) {
            int connected_to = connections[current-1][i];
            if (connected_to != prev)
                surrounding.push_back(connected_to);
        }
        for (int i = 0; i < surrounding.size(); i++) {
            trim_tree(connections, specials, surrounding[i], current, edges_left);
        }
    }

    if (connections[current-1].size() == 1 && current != 1) {
        if (count(specials.begin(), specials.end(), current) == 0) {
            
            int connected_to = connections[current-1][0];
            
            connections[current-1] = {};
            connections[connected_to-1].erase(find(connections[connected_to-1].begin(), connections[connected_to-1].end(), current));

            edges_left--;

        }
    }

}
*/

void trim_tree(vector<vector<int>>& connections, vector<bool>& node_map, vector<int>& specials, int current, int prev) {

    /*
    int deg = 0;
    for (int i = 0; i < connections[current-1].size(); i++) {
        if (node_map[connections[current-1][i]])
            deg++;
    }*/


    for (int i = 0; i < connections[current-1].size(); i++) {
        if (node_map[connections[current-1][i]-1] && connections[current-1][i] != prev) {
            trim_tree(connections, node_map, specials, connections[current-1][i], current);
        }
    }

    int deg = 0;
    for (int i = 0; i < connections[current-1].size(); i++) {
        if (node_map[connections[current-1][i]-1])
            deg++;
    }

    if (deg == 1 && current != 1) {
        if (count(specials.begin(), specials.end(), current) == 0) {
            node_map[current-1] = false;
        }
    }

}

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> specials(K);
    for (int i = 0; i < K; i++)
        cin >> specials[i];

    vector<vector<int>> connections(N);
    for (int i = 0; i < N; i++)
        connections[i] = {};

    for (int i = 0; i < N-1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        connections[v1-1].push_back(v2);
        connections[v2-1].push_back(v1);
    }

    vector<bool> node_map(N);
    for (int i = 0; i < N; i++)
        node_map[i] = true;

    /*
    for (int i = 0; i < connections[5-1].size(); i++) {
        cout << "*" << connections[5-1][i] << endl;
    }
    */

    trim_tree(connections, node_map, specials, 1, -1);

    int nodes_left = 0;
    for (int i = 0; i < N; i++) {
        if (node_map[i])
            nodes_left++;
    }

    int ans = (nodes_left-1) * 2;
    cout << ans << endl;

}
