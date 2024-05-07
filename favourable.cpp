
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <string>

std::map<int, int> mem;

int paths(int current_node, std::vector<std::array<int, 4>>& connections) {

    if (mem.find(current_node) != mem.end())
        return mem[current_node];

    if (current_node == 1) {
        mem[current_node] = 1;
        return 1;
    }
    
    int sum = 0;
    for (int i = 0; i < connections.size(); i++) {
        
        int a, b, c, d;
        a = connections[i][0];
        b = connections[i][1];
        c = connections[i][2];
        d = connections[i][3];

        if (b == current_node || c == current_node || d == current_node)
            sum += paths(a, connections);

    }

    mem[current_node] = sum;
    return sum;

}

int main() {

    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {

        int S;
        std::cin >> S;

        std::vector<std::array<int, 4>> connections;
        std::vector<int> favourable_nodes;

        for (int i = 0; i < S; i++) {

            std::array<std::string, 4> inp;
            std::cin >> inp[0] >> inp[1];

            if (inp[1] == "favourably") {
                favourable_nodes.push_back(std::stoi(inp[0]));
                continue;
            } else if (inp[1] == "catastrophically") {
                continue;
            }

            std::cin >> inp[2] >> inp[3];

            connections.push_back({std::stoi(inp[0]), std::stoi(inp[1]), std::stoi(inp[2]), std::stoi(inp[3])});

        }

        int total_paths = 0;
        for (int i = 0; i < favourable_nodes.size(); i++) {

            total_paths += paths(favourable_nodes[i], connections);

        }

        std::cout << total_paths << std::endl;

    }

}
